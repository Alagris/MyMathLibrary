//
//  mat_helpers.cpp
//  MyMathLibrary
//
//  Created by Alagris on 28/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#include "mat_helpers.hpp"
#include "random.hpp"
#include <iostream>
namespace mymath{
    void randomize(mat&m,const precise min,const precise max){
        generateRandArray(m.ptr(), m.size(), min, max);
    }
    
    void print(const mat&m){
        if(m.columns()==0)return;
        for(size_t r=0;r<m.rows();r++){
            std::cout<<m[0][r];
            for(size_t c=1;c<m.columns();c++)
                std::cout<<","<<m[c][r];
            std::cout<<"\n";
        }
    }
}
