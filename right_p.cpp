//
//  right_p.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "right_p.hpp"
#include "token.hpp"
#include "oper.hpp"
#include <iostream>
#include <string>
#include "types.h"



Right_P::Right_P():Token(")", 4)
{
    
}

Right_P::Right_P(string l)
{
    Token(l, R_PARANTHESES);
    right_p = l;
}

Right_P::~Right_P()
{
    
}

Right_P::Right_P(char l)
{
    string s = "";
    char a = l;
    
    s += a;
    
    right_p = s;
    Token(right_p, R_PARANTHESES);
}

int Right_P::getType()
{
    return R_PARANTHESES;
}

void Right_P::Print()
{
    cout << " )";
}

int Right_P::Prec()
{
    return 0;
}

