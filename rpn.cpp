//
//  rpn.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "rpn.hpp"
#include <iostream>
#include "token.hpp"
#include "number.hpp"
#include "oper.hpp"
#include <string>
#include "left_p.hpp"
#include "right_p.hpp"
#include "queue.h"
#include "stack.h"
#include "types.h"
#include "function.hpp"
#include <cmath>


RPN::RPN (Queue<Token*> r)
{
    input = r;
    while(!r.isEmpty())
    {
        r.dequeue();
    }
}

RPN::RPN(string input_s)
{
    Queue<Token*> post_fix;
    for(int i = 0; i < input_s.length(); i++)
    {
        if(isdigit(input_s[i]) == true)
        {
            Token* new_number_i = new Number(input_s[i]);
            post_fix.enqueue(new_number_i);
        }else if(input_s[i] == '(')
        {
            Token* l_parenth = new Left_P(input_s[i]);
            post_fix.enqueue(l_parenth);
        }else if(input_s[i] == ')')
        {
            Token* r_parenth = new Right_P(input_s[i]);
            post_fix.enqueue(r_parenth);
        }else{
            Token* new_operator = new Oper(input_s[i]);
            post_fix.enqueue(new_operator);
        }
    }
    input = post_fix;
    
    
    while(!post_fix.isEmpty())
    {
        post_fix.dequeue();
    }
}

RPN::~RPN()
{
    while(!input.isEmpty())
    {
        input.dequeue();
    }

}

double RPN::_rpn(double x)
{
    Token* item;
    double answer = 0;
    
    Queue <Token*> copy = input;
    Stack<Token*> result;
    while(!copy.isEmpty())
    {
        item = copy.dequeue();
        int type = item->getType();
        switch(type){
            case NUMBERS : result.push(item);
                break;
            case FUNCTIONS: // INCLUDES X TOO
            {
                string function = static_cast<Function*>(item)->getString();
                if(function == "x" || function == "X")
                {
                    Token* var = new Number(to_string(x));
                    item = var;
                    //item->Print();
                    result.push(item);
                    break;
                }else{
                    string trig = static_cast<Function*>(item)->getString();
                    Token* res = result.Pop();
                    double number = static_cast<Number*>(res)->getNum();
                    double eval = 0;
                    if(trig == "sin" || trig == "SIN")
                    {
                        eval = sin(number);
                    }else if(trig == "cos" || trig == "COS")
                    {
                        eval = cos(number);
                    }else if(trig == "tan" || trig == "TAN")
                    {
                        eval = tan(number);
                    }else if(trig == "sec" || trig == "SEC")
                    {
                        eval = 1/cos(number);
                    }else if(trig == "csc" || trig == "CSC")
                    {
                        eval = 1/sin(number);
                    }else if(trig == "cot" || trig == "COT")
                    {
                        eval = 1/tan(number);
                    }else if(trig == "log" || trig == "LOG")
                    {
                        eval = log(number);
                    }else if(trig == "sq" || trig == "SQ")
                    {
                        eval = sqrt(number);
                    }else if(trig == "negsin" || trig == "NEGSIN")
                    {
                        eval = -(sin(number));
                    }else if(trig == "negcos" || trig == "NEGCOS")
                    {
                        eval = -(cos(number));
                    }else if(trig == "negtan" || trig == "NEGTAN")
                    {
                        eval = -(tan(number));
                    }else if(trig == "negsec" || trig == "NEGSEC")
                    {
                        eval = -(1/cos(number));
                    }else if(trig == "negcsc" || trig == "NEGCSC")
                    {
                        eval = -(1/sin(number));
                    }
                    
                    if(copy.isEmpty() && result.isEmpty())
                    {
                        return eval;
                    }else{
                        string answ = to_string(eval);
                        Token* reslt = new Number(answ);
                        result.push(reslt);
                    }
                }
                
                
                break;
            }
                
            case OPERATORS :
            {
                Token* rght = result.Pop();
                if(result.isEmpty() && copy.isEmpty())
                {
                    answer = static_cast<Number*>(rght)->getNum();
                    return answer;
                }else{
                    Token* lft = result.Pop();
                    double left = static_cast<Number*>(lft)->getNum();
                    double right = static_cast<Number*>(rght)->getNum();
                    answer = static_cast<Oper*>(item)->eval(left, right);
                    string answer_s = to_string(answer);
                    Token*  t_result = new Number(answer_s);
                    result.push(t_result);
                }
                
            }
                
        }
    }
    
    //testing
    while(!input.isEmpty())
    {
        input.dequeue();
    }
    //testing
    while(!result.isEmpty())
    {
        result.Pop();
    }
    return answer;
}

