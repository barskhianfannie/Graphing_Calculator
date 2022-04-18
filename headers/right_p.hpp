//
//  right_p.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef right_p_hpp
#define right_p_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "token.hpp"
#include "oper.hpp"

class Right_P : public Token
{
    
public:
    
    Right_P();
    Right_P(string l);
    Right_P(char l);
    
    ~Right_P();
    
    int getType()override;
    int Prec();
    void Print()override;
    
private:
    
    string right_p;
    
    
};

#endif /* right_p_hpp */
