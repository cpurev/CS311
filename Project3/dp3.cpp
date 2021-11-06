// dp3.cpp  
// Chuluunbat Purev
// 2021-09-20
//
// For CS 311 Fall 2021
// Source for Project 3 functions


#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

//didItThrow
//Checks if given function throws.
//if it does pass the exception setting param threw to true.
//Pre:
//      passed function(ff) must have no parameters and returns void
// Throws whatever ff() threw.
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try{
        ff();
    }
    catch(...){
        threw = true;
        throw;
    }

    threw = false;
}

//gcd
//Find greatest common divisor recursively from given 2 numbers.
//Pre:
//      Passed int cannot be negative and both not zero.
int gcd(int a,
        int b)
{
    if( a == 0) return b;
    
    if( a > b) return gcd(b, a);
    
    return gcd(b%a, a);
}
