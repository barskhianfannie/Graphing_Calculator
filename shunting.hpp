//
//  shunting.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef shunting_hpp
#define shunting_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "token.hpp"

class Shunting_Yard
{
    
public:
    Shunting_Yard();
    Shunting_Yard(string s);
    Shunting_Yard(Queue<Token*> s);
    
    void postFix();
    Queue<Token*> postF();
    
    void change_var(double x)
    {
        x_val = x;
    }
    
    
private:
    
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    double x_val;
};
#endif /* shunting_hpp */
