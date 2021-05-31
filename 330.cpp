/*
 * 330.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    int minPatches(vector<int>& nums, int n) {
        int len=nums.size();
        int idx=0;
        long x=1;

        int patch=0;
        //[1, x-1]
        while(x<=n){
            if(idx<len&&nums[idx]<=x){
                //nums[idx] is covered, just add it to x
                x+=nums[idx];
                idx++;
            }else {
                //nums[idx] is missing, add x to the nums, and the coverage extends from [1, x-1] to [1, 2*x-1]
                x=x*2;
                patch++;
            }
        }

        return patch;
    }
};





int main(){
    return 0;
}

