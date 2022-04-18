//
//  random.hpp
//  Graphing_Calculator
//
//  Created by Fannie Barskhian on 6/9/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include <stdio.h>
class Random
{
public:
    Random();
    int Next(int lo, int hi);
private:
    //----------------------------------------------------------------------
    //static member variable keeps the random number generator from being seeded everytime a
    // new Random object is instantiated.
    //Note the initialization of the static variable in the .cpp file.
    static int objectCount;
    //----------------------------------------------------------------------
};

#endif /* random_hpp */
