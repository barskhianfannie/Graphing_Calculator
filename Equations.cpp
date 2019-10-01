//
//  Equations.cpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/7/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "Equations.hpp"
#include <cmath>


//default contructor
Equations::Equations():evals()
{
    // empty Evaluate Object
   
}
Equations::Equations(string equa):evals(equa)
{
//    try {
//        int l_p = 0;
//        int r_p = 0;
//        for(int i = 0; i < equa.length(); i++)
//        {
//            if(equa[i] == '(')
//            {
//                l_p += 1;
//            }else if(equa[i] == ')')
//            {
//                r_p += 1;
//            }
//
//            if(l_p == r_p)
//            {
//                evals = equa;
//            }else{
//                string test;
//                throw test;
//            }
//        }
//    }
}


//destructor
Equations:: ~Equations()
{
    _rects.clear();
    cout << "EQUATION DESTRUCTOR FIRED" << endl;
}



Equations::Equations(const Equations& eq)
{
    x_min = eq.x_min;
    x_max = eq.x_max;
    y_min = eq.y_min;
    y_max = eq.y_max;
    evals = eq.evals;
    _rects = eq._rects;

}

//updating bounds
void Equations::setBounds(float x_m, float x_x, float y_m, float y_x)
{
    x_min = x_m;
    x_max = x_x;
    y_min = y_m;
    y_max = y_x;
}

void Equations::calculateValuesCircle() // creates graph points
{
    _rects.clear();
    
    double x_pixel_value = (x_max - x_min)/SCREEN_WIDTH_GRAPH; // what each x_pixel value is worth in axis increments.
    double y_pixel_value = (y_max - y_min)/SCREEN_HEIGHT; // what each y_pixel value is worth in axis increments.
    int y_pixel;
    
    for(int i = 0; i < SCREEN_WIDTH_GRAPH; i++)
    {
        double x_val = i * x_pixel_value + x_min; //each x_value to calulate for to fill the graph
        double y_val = evals.eval(x_val); // passing through eval function to get corresponding y_val
        
        y_pixel = (SCREEN_HEIGHT*(y_max - y_val))/(y_max-y_min); //converting the y_val from eval func to y_pixel location
        
        //Uncomment this if I wanna draw circles instead
        
        sf::CircleShape circle;
        circle.setPosition(i, y_pixel);
        circle.setRadius(3);
        _rects.emplace_back(circle);
        
//
//        //To draw graph using rectangles.... this looks better in my opinion
//        sf::RectangleShape rectangle;
//
//        //just for fun making the rgb differen to have a ever changing color change
//        rectangle.setFillColor(sf::Color::White);
//        rectangle.setPosition(i, y_pixel); //setting position before placing into vector
//        if(!_rects.empty()) //checking if empty so that the first rectangle doesnt cause problems
//        {
//            int last_y = _rects.back().getPosition().y; // getting the y position of the laszt rectangle in the vector
//            float r = sqrt(1+pow((y_pixel - last_y), 2)); // calculating r for length of the rectangle in y direction (x is always one)
//            _rects.back().setSize({r,LINE_H}); // changing last rectangles size to meet with new rectangle exactly
//            float rotation = asin((y_pixel - last_y)/r); // calculating roation of rectangle by using arcsin
//            rotation = rotation * 180/3.14159365; // rotation conversion from radians to degrees
//            _rects.back().setRotation(rotation); // setting rotation with sfml setRotation function
//        }
//        _rects.emplace_back(rectangle); // placing into vector of Rectangles for drawing

    }

    
}

//drawing rectangles to form graph in window
void Equations::draw(sf::RenderWindow& window)
{
    for(auto& rect : _rects )
    {
        window.draw(rect);
    }
}

