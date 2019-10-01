//
//  rpn.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef rpn_hpp
#define rpn_hpp

#include <stdio.h>
#include "queue.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "token.hpp"
using namespace std;

class RPN
{
    
public:
    
    RPN(Queue<Token*> r);
    RPN(string input_s);
    ~RPN();
    double _rpn(double x);

    
    
private:
    
    Queue<Token*> input;
    double x_var;
    
};



#endif /* rpn_hpp */
