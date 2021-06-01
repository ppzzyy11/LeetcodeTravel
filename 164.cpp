/*
 * 164.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        for(int i=0; i<nums.size()-1; i++){
            res=max(res, abs(nums[i+1]-nums[i]));
        }

        return res;
    }
};





int main(){
    return 0;
}

