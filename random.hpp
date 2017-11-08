//
//  random.hpp
//  MyMathLibrary
//
//  Created by Alagris on 28/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef random_hpp
#define random_hpp
#include "basic_types.h"
#include <cstdlib>
namespace mymath{
    const precise generateRand(const precise min,const precise max);
    template<typename T>
    void generateRandArray(T arr,const size_t size,const precise min,const precise max){
        for(size_t i=0;i<size;i++)
            arr[i]=generateRand(min, max);
    }
}
#endif /* random_hpp */
