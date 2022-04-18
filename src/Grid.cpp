//
//  Grid.cpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/11/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "Grid.hpp"
#include "specs.h"
#include <iostream>
using namespace std;


Grid::Grid()
{
    
    x_min = -10.0;
    x_max = 10.0;
    y_min = -10.0;
    y_max = 10.0;
    y_pos = 0;
    x_pos = 0;
    offset_x = 0;
    offset_y = 0;
    updateBounds(x_min, x_max, y_min, y_max);
    
}

Grid::~Grid()
{
    grid_lines.clear();
    if(grid_lines.size() == 0)
    {
        cout << "THE GRID HAS BEEN DESTRUCTED" << endl;
    }else{
        cout << "GRID ISNT DESTRUCTING PROPERLY" << endl;
    }
}

void Grid:: updateBounds(float x_m, float x_x, float y_m, float y_x)
{
    x_min = x_m;
    x_max = x_x;
    y_min = y_m;
    y_max = y_x;

}

void Grid::drawLines()
{
    


    for(int i = 0; i < (y_max - y_min); i++)
    {
        y_axis = sf::RectangleShape(sf::Vector2f(1.0f,1800.0f)); // longer for panning?
        y_axis.setFillColor(sf::Color(96,96,96));
        y_axis.setPosition(offset_y, 0);
        grid_lines.emplace_back(y_axis);
        offset_y += SCREEN_WIDTH_GRAPH/(y_max - y_min);


    }
    
    for(int i = 0; i < (x_max - x_min); i++)
    {
        x_axis = sf::RectangleShape(sf::Vector2f(1800.0f,1.0f)); // longer for panning?
        x_axis.setFillColor(sf::Color(96,96,96));
        x_axis.setPosition(0 ,offset_x);
        grid_lines.emplace_back(x_axis);
        offset_x += SCREEN_HEIGHT/(x_max-x_min);
        
    }
    

}


void Grid:: clear()
{
    grid_lines.clear();
}


void Grid:: draw(sf::RenderWindow& window)
{
    
    for(auto& grid : grid_lines)
    {
        window.draw(grid);
    }
}




