//
//  left_p.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "left_p.hpp"
#include "token.hpp"
#include "types.h"


Left_P::Left_P():Token("(", L_PARANTHESES)
{
    
}

Left_P::~Left_P()
{
    
}

Left_P::Left_P(string l)
{
    Token(l, L_PARANTHESES);
    left_p = l;
}

Left_P::Left_P(char l)
{
    string s = "";
    char a = l;
    
    s += a;
    
    left_p = s;
    Token(left_p, L_PARANTHESES);
}

int Left_P::getType()
{
    return L_PARANTHESES;
}

void Left_P::Print()
{
    cout << "(";
}

int Left_P::Prec()
{
    return 0;
}
