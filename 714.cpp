/*
 * 714.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
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
public:
    //assume fee equals 0 first.
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));

        dp[0][0]=-prices[0];//has stocks in hand
        dp[0][1]=0;//has on stocks in hand
        for(int i=1; i<prices.size(); i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][1],prices[i]+dp[i-1][0]-fee);
        }
        return dp.back()[1];
    }
};





int main(){
    return 0;
}

