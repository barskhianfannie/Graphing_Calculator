//
//  number.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef number_hpp
#define number_hpp

#include <stdio.h>
#include "token.hpp"
#include <string>
#include <iostream>
using namespace std;




class Number : public Token
{
    
public:
    
    Number();
    Number(string s_num);
    Number(char c_num);
    
    ~Number();
    
    int getType();
    void Print();
    double getNum();
    
private:
    
    double number;
    
};

#endif /* number_hpp */
