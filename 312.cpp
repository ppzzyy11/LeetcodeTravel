/*
 * 312.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        reverse(nums.begin(), nums.end());

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i+2; j<=n+1; j++){
                for(int k=i+1; k<j; k++){
                    int sum = nums[i]*nums[k]*nums[j];
                    sum+=dp[i][k]+dp[k][j];
                    dp[i][j]=max(dp[i][j], sum);
                }
            }
        }
        return dp[0][n+1];
    }
};





int main(){
    return 0;
}

