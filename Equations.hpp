//
//  Equations.hpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/7/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef Equations_hpp
#define Equations_hpp

#include <stdio.h>
#include <string>
#include "/Users/fanniebarskhian/Desktop/graph_lL/graph_lL/evaluate.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "random.hpp"

#include "specs.h"

/**EQUATIONS CLASS HANDLES ALL THE CALCULATING OF VALUES
 IT SETS THE BOUNDS OF THE GRAPH TO BE -10 TO 10 FOR BOTH THE X AND Y AXIS.
 IT DOES ALL CALCULATIONS FOR PIXEL TO GRAPH COORDINATES. STARTIN FROM -10 TO 10
 MAKES IT SO THAT EACH INCREMENT OF ONE ON THE X-AXIS IS 90 PIXELS. AND THEREFORE,
 EACH INCREMENT OF PIXEL ACCOUNTS FOR 1/90 ON X AXIS VALUE**/


using namespace std;
class Equations
{
public:
    
    Equations();
    Equations(string s);
    ~Equations();
    Equations(const Equations& eq);

    
    //Calculate points (pixel to graph coord for Circles)
    void calculateValuesCircle();
    //Change Bounds for graph manipulations
    void setBounds(float x_m, float x_x, float y_m, float y_x);
    //draw to window
    void draw(sf::RenderWindow& window);
    
    
    
    
private:
    
    //Evaluate Class to handle all shunting yard...etc
    Evaluate evals;
    
    
    //Bounds for calculating graph points
    float x_min;
    float x_max;
    float y_min;
    float y_max;
    
    
//    Uncomment this and other code for using circles
    vector<sf::CircleShape> _rects;
    
//    //Vector of Rectangles for drawing graphs
//    vector<sf::RectangleShape> _rects;
//
    
    
};

#endif /* Equations_hpp */
