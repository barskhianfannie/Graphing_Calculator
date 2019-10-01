//
//  function.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "function.hpp"
#include "token.hpp"
#include <string>
#include "types.h"


Function::Function():Oper()
{
  //Child Class of Operator - Default Oper CTOR
}

Function::Function(string v):func(v), Oper(v)
{
    //Tokenized Function set to private member variable of this class.
}

Function::~Function()
{
    cout << "FUNCTION DESTRUCTOR FIRED" << endl;
    delete this;
}

Function::Function (char v)
{
    string s = "";
    char a = v;
    s += a;
    func = s;

}

int Function::getType()
{
    return FUNCTIONS;
}

void Function::Print()
{
    cout << func ;
}

int Function:: Prec()
{
    return FUNCTIONS;
}

string Function::getString()
{
    return func;
}

