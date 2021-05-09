/*
 * 416.cpp
 * Copyright (C) 2021-05-08 pzy <pzy@pzy-B250M-Wind>
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
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto num:nums)
            sum+=num;
        if(sum%2==1){
            return false;
        }
        vector<bool> pre(sum+1, false);
        vector<bool> cur(sum+1, false);
        pre[0]=true;

        cur=pre;
        for(int i=1; i<n; i++){
            cur[nums[i]]=true;
            for(int j=0; j<=sum; j++){
                cur[j]=cur[j]|pre[j];
                if(j>nums[i]){
                    cur[j]=cur[j]|pre[j-nums[i]];
                }
            }
            pre=cur;
        }
        return cur[sum/2];
    }
};

class SolutionMN {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto num:nums)
            sum+=num;
        if(sum%2==1){
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++){
            int num=nums[i];
            dp[i][num]=true;
        }
        dp[0][0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<=sum; j++){
                dp[i][j]=dp[i][j]|dp[i-1][j];
                if(j>nums[i]){
                    dp[i][j]=dp[i][j]|dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][sum/2];
    }
};





int main(){
    return 0;
}

