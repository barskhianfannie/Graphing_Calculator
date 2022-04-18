//
//  token.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "token.hpp"
#include <iostream>
#include <string>
using namespace std;



Token::Token(): objct(""), _type(0)
{
    
}

Token::Token(string s, int _type): objct(s), _type(0)
{
    
}

Token::~Token()
{
    
}

void Token:: Print()
{
    try{
        string test;
        throw test;
    }
    catch(string)
    {
        cout << "This should not be hitting : Token::Print() " << endl;
    }
}

int Token:: getType()
{
    return _type;
}

string Token::getString()
{
    try{
        string test;
        throw test;
    }
    catch(string)
    {
        cout << "This should not be hitting : Token::getString() " << endl;
    }
    return 0;
}

