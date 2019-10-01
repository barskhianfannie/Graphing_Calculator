//
//  function.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef function_hpp
#define function_hpp

#include <stdio.h>
#include "token.hpp"
#include "oper.hpp"
#include <string>
#include <iostream>


/**Function Class Handles all Variables and Trig Functions
    It is a Child class of Oper Class **/

class Function : public Oper
{
    
public:
    
    Function();
    Function(string v);
    Function (char v);
    ~Function();
    
    int getType() override;
    void Print() override;
    int Prec()override ;
    string getString() override;
    
    
    
private:
    
    string func;
    
};

#endif /* function_hpp */
