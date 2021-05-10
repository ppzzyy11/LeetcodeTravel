/*
 * 486.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class Solution {
    vector<vector<int> > dp;
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n, vector<int>(n, -1));
        int sum=0;
        for(auto& num: nums){
            sum+=num;
        }
        int maxScore=recur(nums, 0, nums.size()-1);
        return maxScore>=( sum+1 )/2;

    }

    int recur(const vector<int>& nums, int s, int e){
        if(s>e){
            return 0;
        }
        if(s==e){
            return nums[s];
        }
        return dp[s][e]=max(nums[s]+min(recur(nums,s+2, e ), recur(nums, s+1, e-1)),
                nums[e]+min(recur(nums,s+1, e-1), recur(nums,s, e-2)));
    }
};





int main(){
    return 0;
}

