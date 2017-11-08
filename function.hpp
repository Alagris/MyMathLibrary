//
//  function.hpp
//  MyMathLibrary
//
//  Created by Alagris on 29/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef function_hpp
#define function_hpp
#include "basic_types.h"
#include <math.h>
#include <stddef.h>
#include "mat.hpp"
namespace mymath {
    typedef const precise (*one_arg_func)(const precise x);
    typedef const precise (*two_arg_func)(const precise x,const precise y);
    typedef const precise (*arr_arg_func)(const precise * x,const size_t count);
    typedef const precise (*mat_arg_func)(const mat & m);
}
#endif /* function_hpp */
