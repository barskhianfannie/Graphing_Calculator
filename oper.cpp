//
//  oper.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "oper.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include "types.h"
using namespace std;



Oper::Oper(string op):_op(op)
{
    
    Token(_op, OPERATORS);
}

Oper::Oper():Token()
{
    
}

Oper::~Oper()
{
    
}

Oper::Oper(char op)
{
    string s = "";
    char a = op;
    
    s += a;
    _op = s;
    
    Token(_op, OPERATORS);
}



void Oper::Print()
{
    cout << _op;
}

int Oper::getType()
{
    return OPERATORS;
}

int Oper::Prec()
{
    string oper = this->_op;
    int prec;
    if(oper == "/")
    {
        prec =  3;
    }else if(oper == "*" )
    {
        prec = 3;
    }else if(oper == "+")
    {
        prec = 2;
    }else if(oper == "-")
    {
        prec = 2;
    }else if(oper == "^")
    {
        prec = 4;
        
    }else{
        cout << "This Type is not rated" << endl;
        return 0;
    }
    return prec;
}

double Oper::eval(double lft, double rght)
{
    double result;
    
    char oper = this->getString()[0];
    
    switch(oper){
        case '+':
            result = lft + rght;
            break;
            
        case '-':
            result = lft - rght;
            break;
            
        case '*':
            result = lft * rght;
            break;
            
        case '/':
            result = lft / rght;
            break;
            
        case '^':
            result = pow(lft, rght);
            break;
        default:
            cout << " ERROR " << endl;
            result = 0.0;
            break;
    }
    return result;
}


string Oper::getString()
{
    return _op;
}

