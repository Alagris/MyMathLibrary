//
//  mat.hpp
//  MyChineLearning
//
//  Created by Alagris on 28/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef mat_hpp
#define mat_hpp

#include "basic_types.h"
#include <memory>
#include <shared_ptr_empty_destructor.h>
#include <fixed_size_dynamic_array.hpp>
namespace mymath {
    class mat{
    public:
        
        
        mat(const size_t columns,const size_t rows,mymath::precise*const buffer=nullptr):
        m_rows(rows),
        m_columns(columns),
        m_arr(size(), buffer){}
        const size_t size()const{return m_rows*m_columns;}
        const size_t rows()const{return m_rows;}
        const size_t columns()const{return m_columns;}
        const size_t rowsOfMultiplicationResult(const mat&m1,const mat&m2)const{return m1.rows();}
        const size_t columnsOfMultiplicationResult(const mat&m1,const mat&m2)const{return m2.columns();}
        const bool isMultiplicationResultAssignable(const mat&m1,const mat&m2)const{
            return rows()>=rowsOfMultiplicationResult(m1, m2)&&columns()>=columnsOfMultiplicationResult(m1, m2);
        }
        const bool isMultiplicationResultExactlyAssignable(const mat&m1,const mat&m2)const{
            return rows()==rowsOfMultiplicationResult(m1, m2)&&columns()==columnsOfMultiplicationResult(m1, m2);
        }
        const mymath::precise at(const size_t index)const{
            return m_arr[index];
        }
        mymath::precise& at(const size_t index){
            return m_arr[index];
        }
        const mymath::precise get(const size_t column,const size_t row)const{
            return at(index(column,row));
        }
        mymath::precise& get(const size_t column,const size_t row){
            return at(index(column,row));
        }
        void set(const size_t column,const size_t row,const mymath::precise val){
            at(index(column,row))=val;
        }
        const size_t index(const size_t column,const size_t row)const{
            return row*m_columns+column;
        }
        const mat operator*(const mat & m)const;
        mat & operator=(const mat & m);
        template<typename T>
        mat & operator=(T*const array){
            for(size_t i=0;i<size();i++)
                at(i)=array[i];
            return *this;
        }
        const bool equalDimentions(const mat & m)const{
            return m.m_rows==m_rows&&m.m_columns==m_columns;
        }
        const bool compatibleDimentions(const mat & m)const{
            return m.m_rows==m_columns||m.m_columns==m_rows;
        }
        const bool multiplicableBy(const mat & m)const{
            return m.m_rows==m_columns;
        }
        mymath::precise *const ptr(){return m_arr;}
        const mymath::precise *const ptr()const{return m_arr;}
        class slice{
        private:
            friend mat;
            slice(const mat * const parent,const size_t column):
            m_parent(parent),
            m_column(column){}
        public:
            const mymath::precise operator[](const size_t row)const{
                return m_parent->get(m_column,row);
            }
        private:
            const mat * const m_parent;
            const size_t m_column;
        };
        
        const slice operator[](const size_t column)const{
            return slice(this,column);
        }
        slice operator[](const size_t column){
            return slice(this,column);
        }
        
        void fillWithNaN();
        void fill(const mymath::precise val=0);
        void assign(const mat & m1,const mat & m2);
        
    private:
        mat(const mat & m1,const mat & m2):
        m_columns(m2.columns()),
        m_rows(m1.rows()),
        m_arr(size())
        {
            assign(m1, m2);
        }
        
        size_t m_rows;
        size_t m_columns;
        util_lib::fixed_size_dynamic_array<mymath::precise> m_arr;
    }const EMPTY_MAT(0,0);
    
    
    
}
#endif /* mat_hpp */
