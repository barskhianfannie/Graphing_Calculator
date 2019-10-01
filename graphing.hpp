//
//  graphing.hpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/2/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef graphing_hpp
#define graphing_hpp

#include <stdio.h>
#include <vector>
#include "specs.h"
#include "Equations.hpp"
#include <list>
#include <string>
#include "Grid.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class graphing
{
public: 
    graphing(); // this will set up graph with x-axis ,y-axis, and sidebar
    void processEvents(); // procress all user input events
    void run(); //while the window is open this will call continuously call processEevents and render
    void draw(); // draws all of the necessary components of the graph
    void render();  //clear / draw / display
    void resetBounds();
    ~graphing();
    
private:
    
    sf::RenderWindow window; // reates window
    sf::RectangleShape x_axis; // x_axis
    sf::RectangleShape y_axis; //y_axis
    sf::RectangleShape sidebar; //sidebar
    
    //All sfml stuff needed for input to show on the screen
    sf::Text text;
    sf::Font myFont;
    sf::String Input;
    
    /** List of Equations which is a class that has and Evaluate private member value which will call eval
        to calculate the y values to corresponding x values. This class handles all of the pixel to graph
        conversions. With each point on the graph, it will create a Circle with corresponding position.
        Each individual circle shape is pushed into the vector of circles for drawing purposes.
     **/
    list<Equations> _eq;

    /** For Bound Calculation communication with the Equations Class
        The bounds will begin at -10 to 10 for both the x and y axis
        When the user presses Z for Zoom the Bounds will change to
        in increments of 1. When the directions arrows are presssed
        the bounds will also change accordingly.
     **/
    float x_min;
    float x_max;
    float y_min;
    float y_max;

    
    /** Panning Right / Left / Up / Down by calculating the offset values of y and x
        depending on the bounds of the graph the amount of pixels needed to move the x or y
        axis to the appropiate pixel position in the window in conjuction with the bounds of axis changing
     **/
    
    float offset_y; // for panning right and left
    float offset_x; // for panning up and down
    
    
    /**These Private Member Variables are used for handling the menu in the sidebar **/
    
    vector<sf::Text> print_eq; // vector of sfml Texts so that we can print the menu
    float text_x_pos; //to keep track of history menu positions (this number stays the same)
    float text_y_pos; //to keep track of menu positions ( this number increments by 100 pixels to allow for space)
    int menu_count; // count to sort through menu in sidebar for the try and catch code
    
    
    list <Grid> grid_lines;
    Grid g;
    
};

#endif /* graphing_hpp */
