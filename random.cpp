//
//  random.cpp
//  MyMathLibrary
//
//  Created by Alagris on 28/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#include "random.hpp"
#include <cstdlib>

namespace mymath{
    const precise generateRand(const precise min,const precise max){
        const int precission =1000;
        precise r= rand()%precission;
        return (max-min)*r/precission+min;
    }
}
