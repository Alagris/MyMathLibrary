//
//  mat.cpp
//  MyChineLearning
//
//  Created by Alagris on 28/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#include "mat.hpp"
#include <math.h>
namespace mymath{
    const mat mat::operator*(const mat & m)const{
        if(!multiplicableBy(m))return EMPTY_MAT;
        return mat(*this,m);
    }
    mat & mat::operator=(const mat & m){
        for(size_t r=0;r<rows();r++)
            for(size_t c=0;c<columns();c++)
                set(c,r,m.get(c,r));
        return *this;
    }
    void mat::fillWithNaN(){
        fill(NAN);
    }
    void mat::fill(const mymath::precise val){
        for(size_t i=0;i<size();i++)
            at(i)=val;
    }
    
    void mat::assign(const mat & m1,const mat & m2){
        if(m1.multiplicableBy(m2)&&isMultiplicationResultAssignable(m1, m2))
            for(size_t r=0;r<rowsOfMultiplicationResult(m1, m2);r++)
                for(size_t c=0;c<columnsOfMultiplicationResult(m1, m2);c++){
                    mymath::precise val=0;
                    for(size_t i=0;i<m1.columns();i++){
                        const mymath::precise ir=m1.get(i,r);
                        const mymath::precise ci=m2.get(c,i);
                        const mymath::precise irci=ir*ci;
                        if(irci!=NAN)
                            val+=irci;
                    }
                    set(c,r,val);
                }
        else
            fillWithNaN();
    }
}
