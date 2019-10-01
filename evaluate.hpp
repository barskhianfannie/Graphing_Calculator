//
//  evaluate.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef evaluate_hpp
#define evaluate_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include "token.hpp"
#include "shunting.hpp"


class Evaluate
{
public:
    
    Evaluate();
    Evaluate(string s);
    ~Evaluate();
    
    
    
    double eval(double var_value = 1);
    
private:
    
    Queue<Token*> _infix;
    
};
#endif /* evaluate_hpp */
