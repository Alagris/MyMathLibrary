//
//  functions.hpp
//  MyMathLibrary
//
//  Created by Alagris on 20/01/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef functions_hpp
#define precise functions_hpp
#include <cmath>
#include "basic_types.h"
namespace mymath{
    /**
     * @param a
     *            - the half width
     * @param b
     *            - controls the slopes at the crossover points
     * @param c
     *            - center
     */
    constexpr precise funcBellShaped(x,a,b,c){
        return 1 / (1 + std::pow(std::abs((x - c) / a), 2 * b));
    }
    
    /** @param o - center of circle
     @param r - radius */
    constexpr precise funcCIRCLE_HALF(z,o,r){
        return std::sqrt(r * r - std::pow(std::abs(o - x), 2));
    }
    /**
     * @param center
     *            - point where membership is 1
     * @param sigma
     *            - standard deviation
     */
    constexpr precise funcGAUSSIAN(x,center,sigma){
        return std::exp(-std::pow((x - center) / sigma, 2));
    }
    /**
     * @return always -1 (x<=0) or 1 (x>0)
     */
    constexpr precise funcHEAVISIDE_STEP_BIPOLAR(x){
        return  (x > 0) ? 1 : -1
    }
    
    /**
     * @return always 0 (x<=0) or 1 (x>0)
     */
    constexpr precise funcHEAVISIDE_STEP_UNIPOLAR(x){
        return  (x > 0) ? 1 : 0
    }
    
    constexpr precise funcINTERVAL(x,inclusiveBeginning,inclusiveEnd){
        return  (x>=inclusiveBeginning && x<=inclusiveEnd)? 1:0
    }
    
    /**
     * @param b
     *            - minimum x - lowest membership
     * @param a
     *            - top value where membership is 1
     */
    constexpr precise funcL(x,a,b){
        return  x<=a?1:(x>=b?0:( (b - x) / (b - a)))
    }
    
    /** Standard linear function
     @return y = x*a + b */
    constexpr precise funcLINEAR(x,a,b){
        return  x * a + b;
    }
    
    /**
     * @param a
     *            - minimum x - lowest membership
     * @param b
     *            - middle value where membership is a half
     * @param c
     *            - maximum x - highest membership
     */
    inline precise funcMembershipS(const precise x,const precise a,const precise b,const precise c)
    {
        if (x > c)
        { // over max
            return 1;
        }
        else if (x <= a)
        { // minimum reached
            return 0;
        }
        else if (a < x && x <= b)
        {
            return 2 * (std::pow(x - a, 2) / std::pow(c - a, 2));
        }
        else
        { // b < x <= c
            return 1 - 2 * (std::pow(x - c, 2) / std::pow(c - a, 2));
        }
        
    }
    /**
     * @param c
     *            - place where this function will return 1 - top point
     * @param b
     *            - length of function
     */
    inline precise funcMembershipPi(const precise x,precise b,precise c){
        
        if (x >= c)
        {
            //back
            precise a =c;
            c = c + b;
            b=a + (c - a) / 2;
            return 1 - funcMembershipS(x,a,b,c);
        }
        else
        { // x<c
            //front
            precise a = c - b;
            //c = c;
            b=a + (c - a) / 2;
            return funcMembershipS(x,a,b,c);
        }
    }
    inline precise funcSigmoidBipolar(const precise x,const precise beta){
        const precise d = std::exp(beta * x);
        return (1 - d) / (1 + d);
    }
    constexpr precise funcPARABOLA(x,focusPointY,focusPointX){
        return   (std::pow(focusPointY, 2) - std::pow((x - focusPointX), 2)) / (-2 * focusPointY) + focusPointY;
    }
    
    /**@return negResult if x<0, posResult if x>0, posResult if x=0 */
    constexpr precise funcPOLAR_ZERO_POSITIVE(x,negResult,posResult){
        return   x<0?negResult:posResult;
    }
    
    /**@return negResult if x<0, posResult if x>0, negResult if x=0 */
    constexpr precise funcPOLAR_ZERO_NEGATIVE(x,negResult,posResult){
        return   x>0?posResult:negResult;
    }
    
    /**@return negResult if x<0, posResult if x>0, 0 if x=0 */
    constexpr precise funcPOLAR_ZERO_NEUTRAL(x,negResult,posResult){
        return   x==0?0:(x>0?posResult:negResult);
    }
    
    constexpr precise funcSIGMOID_UNIPOLAR(x,beta){
        return   1 / (1 + std::exp(-beta * x));
    }
    
    /**
     * @param a
     *            - value that is accepted
     */
    constexpr precise funcSINGLETON(x,a){
        return   x==a;
    }
    
    /**
     * @param a
     *            - back x - lowest membership
     * @param b
     *            - middle value where membership is 1
     * @param c
     *            - front x - lowest membership
     */
    inline precise funcT(const precise x,const precise a,const precise b,const precise c){
        if (x <= a)
        { // minimum reached
            return 0;
        }
        else if (x >= c)
        {// x is over top
            return 0;
        }
        else
        { // a < x < c
            if (x > b)
            {
                return (c - x) / (c - b);
            }
            else
            { // x<=b
                return (x - a) / (b - a);
            }
        }
    }
}
#endif /* functions_hpp */
