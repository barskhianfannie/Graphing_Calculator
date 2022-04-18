//
//  token.hpp
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Token
{
    
public:
    
    Token();
    virtual ~Token();
    Token(string s, int _type);
    
    virtual void Print();
    virtual int getType();
    virtual string getString();
    
    friend ostream& operator <<(ostream& outs, Token& t)
    {
        t.Print();
        return outs;
    }
    
    friend ostream& operator <<(ostream& outs, Token* t)
    {
        t->Print();
        return outs;
    }
    
private:
    
    string objct;
    int _type;
    
    
};

#endif /* token_hpp */
