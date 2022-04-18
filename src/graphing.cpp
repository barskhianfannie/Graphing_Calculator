//
//  graphing.cpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/2/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "graphing.hpp"
#include "ResourcePath.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <fstream>


using namespace std;



graphing::graphing()
{
    
    
    //instantiating window with options of resize and closing window
    cout << "Calculator Window CTOR " << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Fannie's Graphing Calculator", sf::Style::Close | sf::Style::Resize);// y/x

    
    //x axis constructor
    x_axis = sf::RectangleShape(sf::Vector2f(1800.0f,13.0f)); // longer for panning ?
    x_axis.setFillColor(sf::Color(230,230,250));
    x_axis.setPosition(0,X_AXIS_POS);
    
    //y-axis constructor
    y_axis = sf::RectangleShape(sf::Vector2f(13.0f,1800.0f)); // longer for panning?
    y_axis.setFillColor(sf::Color(230,230,250));
    y_axis.setPosition(Y_AXIS_POS, 0);
    
    //sidebar constructor
    sidebar = sf::RectangleShape(sf::Vector2f(SIDE_BAR_WIDTH, SIDE_BAR_HEIGHT));
    sidebar.setPosition(SCREEN_WIDTH_GRAPH, 0); // where the graph ends, the sidebar begins !
    sidebar.setFillColor(sf::Color(96,96,96));
    
    //text handling for the input from keyboard
    myFont.loadFromFile(resourcePath() + "sansation.ttf");
    text.setFillColor(sf::Color::White);
    text_x_pos = SCREEN_WIDTH_GRAPH + 10;
    text_y_pos = 100;
    text.setPosition(SCREEN_WIDTH_GRAPH + 10, 100);
    text.setFont(myFont);

    
    //setting bounds to -10 to 10 for both axis
    x_min = -10.0;
    x_max = 10.0;
    y_min = -10.0;
    y_max = 10.0;
    
    //initialize count for menu
    menu_count = 0;
    
    //this is used for panning....
    offset_y = float(Y_AXIS_POS);
    offset_x = float(X_AXIS_POS);
    
    grid_lines.emplace_back(Grid());
    

}
graphing::~graphing()
{
    while(!_eq.empty())
    {
        _eq.pop_back(); // deletes pointer
        cout << "DESTRUCTED" << endl;
    }
}


void graphing:: resetBounds()
{
    x_min = -10.0;
    x_max = 10.0;
    y_min = -10.0;
    y_max = 10.0;
    y_axis.setPosition(Y_AXIS_POS, 0);
    x_axis.setPosition(0,X_AXIS_POS);
    
    
}


void graphing::processEvents()
{
    sf::Text eqHistory;

        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::Resized :
                {
                    cout <<  "New Window Width : " << evnt.size.width << "  New Window Height :" << evnt.size.height << endl;
                    break;
                }
                case sf::Event::TextEntered:
                {
                    if(evnt.text.unicode > 31 && evnt.text.unicode < 127 && evnt.text.unicode != 122 && evnt.text.unicode != 114
                     && evnt.text.unicode != 32 && evnt.text.unicode != 90)//  excluding z for zoom and r for reset
                    {
                        Input += char(evnt.text.unicode);
                        text.setString(Input);
                    }
                    if(evnt.text.unicode == '\b') //backspace
                    {
                        try{
                            if(Input.getSize() == 0)
                            {
                                string test;
                                throw test;
                            }else{
                                Input.erase(Input.getSize() - 1, 1);
                                text.setString(Input);
                            }
                        }
                        catch(string){
                            cout << "Can't BackUp anymore " << endl;
                        }
                    }
                    if(evnt.text.unicode == 10) // enter ... return to evaluate and graph the input on sidebar
                    {
                        if(!Input.isEmpty())
                        {
                            text_y_pos += 50;
                            text.setPosition(text_x_pos,text_y_pos);
                            print_eq.emplace_back(text);
                            text.setPosition(SCREEN_WIDTH_GRAPH+10, 100);
                            _eq.clear();
                            /** Convering Input to String so that it can be constructed with Equation **/
                            _eq.emplace_back(Input.toAnsiString());
                            Input.clear();
                            text.setString(Input);
                            
                        }
                    }
      
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    sf::Mouse mouse;
                    sf::Vector2i mousPos = mouse.getPosition();
                    if(mousPos.x == 2082)
                    {
                        cout << mousPos.x << endl;
                    }
                    
                }
                case sf::Event::KeyPressed:
                {
                    if (evnt.key.code == sf::Keyboard::Z)// Zoom for Zooming into the Graph (Bounds calculated change to -5 to 5)
                    {
                        x_min += 1;;
                        x_max -= 1;
                        y_min += 1;
                        y_max -= 1;
                        if(x_min == 0 && x_max == 0 && y_min == 0 && y_max == 0){
                            cout << "ZOOMED IN TOO FAR , RESETTING BOUNDS" << endl;
                            resetBounds();
                            Grid new_g;
                            grid_lines.emplace_back(new_g);
                        }else{
                            grid_lines.clear();
                            g.updateBounds(x_min, x_max, y_min, y_max);
                            grid_lines.emplace_back(g);
                        }
                    }else if(evnt.key.code == sf::Keyboard::R)// Restore to Restore the Graph back to original Bounds
                    {
                        x_min = -10;
                        x_max = 10;
                        y_min = -10;
                        y_max = 10;
                        y_axis.setPosition(float(Y_AXIS_POS), 0.0);
                        x_axis.setPosition(0.0, float(X_AXIS_POS));
                        offset_y = float(Y_AXIS_POS);
                        offset_x = float(X_AXIS_POS);
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Left)
                    {
                        x_min -= 1;
                        x_max -= 1;
                        offset_y += SCREEN_WIDTH_GRAPH/(x_max-x_min); // Increments by 1 on both sides of x-axis (calculating pixels)
                        y_axis.setPosition(float(offset_y),0.0);
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Right)
                    {
                        x_min += 1;
                        x_max += 1;
                        cout << x_min << x_max << endl;
                        offset_y -= SCREEN_WIDTH_GRAPH/(x_max-x_min); // Decrements by 1 on both sides of x-axis (calculating pixels)
                        y_axis.setPosition(float(offset_y),0.0);
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Up)
                    {
                        y_max -= 1;
                        y_min -= 1;
                        offset_x -= SCREEN_HEIGHT/(y_max-y_min); // Decrements by 1 on both sides of y-axis (calculating pixels)
                        x_axis.setPosition(0.0,float(offset_x));
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Down)
                    {
                        y_min += 1;
                        y_max += 1;
                        offset_x += SCREEN_HEIGHT/(y_max-y_min); // Increments by 1 on both sides of y-axis (calculating pixels)
                        x_axis.setPosition(0.0, float(offset_x));
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Escape)
                    {
                        resetBounds(); // reset back to -10 to 10
                        _eq.clear();
                        print_eq.clear();
                        text_x_pos = SCREEN_WIDTH_GRAPH + 10;
                        text_y_pos = 100;
                        menu_count = 0;
                        grid_lines.clear();
                        g.updateBounds(x_min, x_max, y_min, y_max);
                        grid_lines.emplace_back(g);
                    }else if(evnt.key.code == sf::Keyboard::Space) // Space Used for movement through menu
                    {
                        _eq.clear();
                        try
                        {
                            if(print_eq.size() <= menu_count)
                            {
                                throw menu_count;
                            }
                            sf::Text hst = print_eq[menu_count];
                            hst.setFillColor(sf::Color::Red);
                            string history = hst.getString();
                            _eq.emplace_back(history);
                            menu_count += 1;
                        }
                        catch(int)
                        {
                            cout << "END OF MENU : MENU SIZE IS: " << menu_count-1 << endl;
                        }
                        
                    }
                    
                    break;
                }
                    
            }
            
            
        }
    
}

//continuously drawing all elements of the graph !
void graphing::draw()
{

    window.draw(x_axis);
    window.draw(y_axis);
    window.draw(sidebar);
    window.draw(text);
    for(auto& print : print_eq)
    {
        window.draw(print);
        
    }
    
    //contiuously updating the bounds for accurate point calculations with respect to graph manipulations
    for(auto& e : _eq)
    {
        e.setBounds(x_min, x_max, y_min, y_max);
        e.calculateValuesCircle();
        e.draw(window);
    }

    
    for(auto& g : grid_lines)
    {
        g.updateBounds(x_min, x_max, y_min, y_max);
        g.drawLines();
        g.draw(window);
    }

}

//rendering to clear window / draw / then display continuously updating itself
void graphing::render()
{
    window.clear();
    draw();
    window.display();
}


//while the window is open. events are being processed and passed to render for continuous execution
void graphing::run()
{
 
    while(window.isOpen())
    {
        processEvents();  //window stuff
        render();
    }
}






