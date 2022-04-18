//
//  shunting.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "shunting.hpp"
#include "number.hpp"
#include "oper.hpp"
#include "left_p.hpp"
#include "right_p.hpp"
#include "queue.h"
#include "stack.h"
#include "function.hpp"
#include <iostream>
#include <string>
#include "types.h"
using namespace std;

Shunting_Yard::Shunting_Yard()
{
    
}

Shunting_Yard::Shunting_Yard(string s)
{
    
    string copy;
    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]) == true)
        {
            Token* new_numb = new Number(s[i]);
            _infix.enqueue(new_numb);
        }else if(s[i] == '(')
        {
            Token* l_parenth = new Left_P();
            _infix.enqueue(l_parenth);
        }else if(s[i] == ')')
        {
            Token* r_parenth = new Right_P();
            _infix.enqueue(r_parenth);
        }else if(s[i] == '+' || s[i] == '*' || s[i] == '^' || s[i] == '/' || s[i] == '-')
        {
            Token* opt = new Oper(s[i]);
            _infix.enqueue(opt);
        }else{
            copy.push_back(s[i]);       // adding i to possible trig functions
            if(copy == "sin" || copy == "x" || copy == "tan" || copy == "cos" || copy == "csc" ||copy == "sec" || copy == "cot")
            {
                Token* function = new Function(copy);
                _infix.enqueue(function);
                copy.clear();
            }
        }
    }
    
}

Shunting_Yard::Shunting_Yard(Queue<Token*> s)
{
    _infix = s;
}


Queue<Token*> Shunting_Yard:: postF()
{
    Stack<Token*> operators;
    
    
    while(!_infix.isEmpty())
    {
        Token* deque = _infix.dequeue();

        switch(deque->getType())
        {
            case NUMBERS :
            {
                _postfix.enqueue(deque);
                break;
            }
            case OPERATORS :
            {
                while(!operators.isEmpty())
                {
                    Token * top_op = operators.Top();
                    if(top_op->getType() == L_PARANTHESES)
                    {
                        operators.push(deque);
                        break;
                    }else if(top_op->getType() == R_PARANTHESES)
                    {
                        cout << "hit " << endl;
                        operators.Pop();
                        break;
                    }else if(top_op->getType() == FUNCTIONS)
                    {
                        _postfix.enqueue(operators.Pop());
                        operators.push(deque);
                        break;
                    }else if(static_cast<Oper*>(deque)->Prec() <= static_cast<Oper*>(top_op)->Prec())
                    {
                        _postfix.enqueue(operators.Pop());
                        if(operators.isEmpty())
                        {
                            break;
                        }
                    }else{
                        operators.push(deque);
                        break;
                    }
                }
                
                if(operators.isEmpty())
                {
                    operators.push(deque);
                }
                break;
            }
                
            case L_PARANTHESES : operators.push(deque);
                break;
            case R_PARANTHESES :
            {
                Token * top_op = operators.Top();
                while(!operators.isEmpty() && top_op->getType() != L_PARANTHESES)
                {
                    _postfix.enqueue(operators.Pop());
                    top_op = operators.Top();// POP
                }
                if(top_op->getType() == L_PARANTHESES)
                {
                    operators.Pop();
                }
                break;
            }
            case FUNCTIONS:
            {
                if(deque->getString() == "x")
                {
                    _postfix.enqueue(deque);
                    break;
                }else{
                    operators.push(deque);
                    break;
                }
                
                
                
            }
        }
    }
    
    
    while(!operators.isEmpty())
    {
        
        _postfix.enqueue(operators.Pop());
    }
    
    
    return _postfix;
}

void Shunting_Yard::postFix()
{
    //cout << _postfix;
}

