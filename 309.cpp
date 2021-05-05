/*
 * 309.cpp
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MIN));
        //0 for buying
        //1 for selling
        //2 for cooldown
        for(int i=0; i<n; i++){
            if(i==0){
                dp[i][0]=-prices[i];
                dp[i][1]=0;
                dp[i][2]=0;
            }else if(i==1){
                dp[i][0]=max(dp[i-1][0], -prices[i]);
                dp[i][2]=max(0, prices[i]+dp[i-1][0]);
                dp[i][1]=0;
            }else{
                dp[i][0]=max(dp[i-1][0], dp[i-2][2]-prices[i]);
                dp[i][1]=max(dp[i-1][1], dp[i-1][2]);
                dp[i][2]=max(dp[i-1][2], dp[i-1][0]+prices[i]);
            }
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};





int main(){
    return 0;
}

