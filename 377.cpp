/*
 * 377.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0]=1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=target; i++){
            for(auto num: nums){
                //The answer is guaranteed to fit in a 32-bit integer.
                //!!!!!!! so there is a striction that dp[i+num]<INT_MAX-dp[i]!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                if(i+num<=target&&dp[i+num]<INT_MAX-dp[i]){
                    dp[i+num]+=dp[i];
                }else{
                    break;
                }
            }
        }
        return dp.back();
    }
};





int main(){
    return 0;
}

