/*
 * 260.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(const int& num: nums){
            x^=num;
        }

        int div=1;
        while((div&x)==0){
            div<<=1;
        }

        int a=0,b=0;
        for(const int& num: nums){
            if(num&div){
                a^=num;
            }else{
                b^=num;
            }
        }
        return {a, b};
    }
};





int main(){
    return 0;
}

