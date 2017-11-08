////
////  vec.hpp
////  MyChineLearning
////
////  Created by Alagris on 28/10/2017.
////  Copyright © 2017 alagris. All rights reserved.
////
//
//#ifndef vec_hpp
//#define vec_hpp
//#include "basic_types.h"
//#include <memory>
//namespace mymath {
//    class vec{
//    public:
//        vec(const vec & v):
//            m_size(v.m_size),
//            m_ptr(v.m_ptr){}
//        vec(const size_t size):
//            m_size(size),
//            m_ptr(new mymath::precise[size]){}
//         const size_t size()const{return m_size;}
//         const mymath::precise operator[](const size_t i)const{return m_ptr.get()[i];}
//         mymath::precise & operator[](const size_t i){return m_ptr.get()[i];}
//         mymath::precise *const ptr(){return m_ptr.get();}
//         const mymath::precise *const ptr()const{return m_ptr.get();}
//        const vec operator*(const vec & v)const;
//        vec & operator=(const vec & v);
//        template<typename T>
//        vec & operator=(T * const array){
//            for(size_t i=0;i<m_size;i++)
//                operator[](i)=array[i];
//            return *this;
//        }
//        const bool multiplicableBy(const vec & v)const{
//            return v.size()==size();
//        }
//    private:
//        vec(const vec & v1,const vec & v2);
//        const size_t m_size;
//        const std::shared_ptr<mymath::precise> m_ptr;
//    }const EMPTY_VEC(0);
//}
//#endif /* vec_hpp */
