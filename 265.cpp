/*
 * 265.cpp
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
    int minCostII(vector<vector<int>>& costs) {
        int m=costs.size();
        int n=costs[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0){
                    dp[i][j]=costs[i][j];
                }else{
                    for(int k=0; k<n; k++){
                        if(k==j){
                            continue;
                        }
                        dp[i][j]=min(dp[i][j], dp[i-1][k]+costs[i][j]);
                    }
                }
            }
        }

        int res=INT_MAX;
        for(int i=0; i<n; i++){
            res=min(res, dp[m-1][i]);
        }


        return res;
    }
};





int main(){
    return 0;
}

