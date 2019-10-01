//
//  oper.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef oper_hpp
#define oper_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include "token.hpp"
#include <iostream>
using namespace std;

class Oper : public Token
{
    
public:
    
    Oper();
    Oper(string op);
    Oper(char op);
    
    ~Oper();
    
    virtual int Prec();
    virtual void Print();
    virtual int getType();
    string getString();
    double eval(double lft, double rght);
    
private:
    
    string _op;
    int _prec;
    
    
};

#endif /* oper_hpp */
