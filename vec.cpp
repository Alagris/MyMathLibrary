////
////  vec.cpp
////  MyChineLearning
////
////  Created by Alagris on 28/10/2017.
////  Copyright © 2017 alagris. All rights reserved.
////
//
//#include "vec.hpp"
//#include <math.h>
//namespace mymath{
//    vec::vec(const vec & v1,const vec & v2):
//        m_size(1),
//        m_ptr(new mymath::precise)
//    {
//        auto val=*m_ptr;
//        if(v1.size()==v2.size()){
//            val=0;
//            for(size_t i=0;i<v1.size();i++)
//                val+=v1[i]*v2[i];
//        }else{
//            val=NAN;
//        }
//    }
//    const vec vec::operator*(const vec & v)const{
//        if(!multiplicableBy(v))return EMPTY_VEC;
//        return vec(*this,v);
//    }
//    vec & vec::operator=(const vec & v){
//        for(size_t i=0;i<m_size;i++)
//            operator[](i)=v[i];
//        return *this;
//    }
//}
