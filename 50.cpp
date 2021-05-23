/*
 * 50.cpp
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
    double myPow(double x, int n) {
        double res=1;
        bool neg=(n<0);
        unsigned int un=(n==INT_MIN?(1<<31):abs(n));
        while(un){
            if(un&1){
                res=res*x;
            }
            un=(un>>1);
            x=x*x;
        }
        return neg?1.0/res:res;
    }

};





int main(){
    return 0;
}

