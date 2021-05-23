/*
 * 29.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 * Description:
 *
 *      To implement:
 *      How:
 */
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;



class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1){
            return INT_MAX;
        }
        bool neg=false;
        if(dividend<0){
            neg=!neg;
        }
        if(divisor<0){
            neg=!neg;
        }

        unsigned int a = int2unint(dividend);
        unsigned int b = int2unint(divisor);

        unsigned int res=0;

        int i=31;
        while(i>=0&&a>=b){
            if(!overflow(b, i)){
                if(a>=(b<<i)){
                    res|=(1<<i);
                    a-=(b<<i);
                }
            }
            i--;
        }

        return res*(neg?-1:1);


    }

    unsigned int int2unint(int num){
        unsigned int res=0;
        if(num==INT_MIN){
            res=(1<<31);
        }else{
            res=abs(num);
        }
        return res;

    }

    bool overflow(unsigned int num, int i){
        while(i>0){
            if(num&(1<<31)){
                return true;
            }
            num=num<<1;
            i--;
        }
        return false;
    }

};





int main(){
    return 0;
}

