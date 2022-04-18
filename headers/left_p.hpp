//
//  left_p.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef left_p_hpp
#define left_p_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "token.hpp"

#include <stdio.h>

class Left_P : public Token
{
    
public:
    
    Left_P();
    Left_P(string l);
    Left_P(char l);
    
    ~Left_P();
    
    int getType()override;
    int Prec();
    void Print();
    
private:
    
    string left_p;
    
    
};

#endif /* left_p_hpp */
