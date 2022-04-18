//
//  number.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "number.hpp"
#include <string>
#include <iostream>
#include "types.h"
using namespace std;


Number::Number():Token()
{
    
}

Number::~Number()
{
    
}


Number::Number(string s_num)
{
    Token(s_num, NUMBERS);
    number = stod(s_num);
}

Number::Number(char c_num)
{
    string s = "";
    char a = c_num;
    
    s += a;
    Token(s, NUMBERS);
    number = stod(s);
}


int Number:: getType()
{
    return NUMBERS;
}

void Number:: Print()
{
    cout << number ;
}

double Number::getNum()
{
    return number;
}

