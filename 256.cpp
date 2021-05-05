/*
 * 256.cpp
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
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();//m houses
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        for(int i=0; i<n; i++){
            if(i==0){
                dp[i][0]=costs[i][0];
                dp[i][1]=costs[i][1];
                dp[i][2]=costs[i][2];
                continue;
            }else{
                dp[i][0]=min(dp[i-1][1],dp[i-1][2])+costs[i][0];
                dp[i][1]=min(dp[i-1][0],dp[i-1][2])+costs[i][1];
                dp[i][2]=min(dp[i-1][0],dp[i-1][1])+costs[i][2];
            }
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};





int main(){
    return 0;
}

