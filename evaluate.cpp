//
//  evaluate.cpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#include "evaluate.hpp"
#include <string>
#include "token.hpp"
#include "number.hpp"
#include "oper.hpp"
#include "left_p.hpp"
#include "right_p.hpp"
#include "rpn.hpp"
#include "shunting.hpp"
#include "function.hpp"


//Empty Default Constructor
Evaluate::Evaluate()
{
    Shunting_Yard();
}

//Tokenizer to tokenize each char of the the string input and place ito _infix queue to be passed to Shunting Yard
Evaluate::Evaluate(string s)
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
            copy.push_back(s[i]);       // adding i to  str copy to find  possible trig functions
            if(copy == "sin" || copy == "x" || copy == "tan" || copy == "cos"
               || copy == "csc" ||copy == "sec" || copy == "cot" || copy == "log" || copy == "sq"
               || copy == "SIN" || copy == "X" || copy == "TAN" || copy == "COS"
               || copy == "CSC" ||copy == "SEC" || copy == "COT" || copy == "LOG" || copy == "SQ"
               || copy == "negsin" || copy == "NEGSIN" || copy == "negcos" || copy == "NEGCOS"
               || copy == "negtan" || copy == "NEGTAN" || copy == "negcsc" || copy == "NEGCSC"
               || copy == "negsec" || copy == "NEGSEC")
            {
                Token* function = new Function(copy);
                _infix.enqueue(function);
                copy.clear();
            }else if (copy == "sign") //this is trash... not working well 
            {
                string neg = "-1";
                Token* negative = new Number(neg);
                _infix.enqueue(negative);

            }
        }
    }
    
}

//Destructing each individual item in the Queue.... dequeue calls delete node
Evaluate::~Evaluate()
{
    while(!_infix.isEmpty())
    {
        _infix.dequeue();
    }
    
    cout << "EVALUATE DESTRUCTOR FIRED" << endl;
}

//Handles all of the evaluations by calling Shunting Yard and RPN
double Evaluate::eval(double var_value)
{
    Shunting_Yard sh_y(_infix);
    Queue<Token*> post = sh_y.postF();
    //    sh_y.postFix(); // print postfix for testing
    RPN rpn(post);
    double value ;
    value = rpn._rpn(var_value);
    
    return value;
}


