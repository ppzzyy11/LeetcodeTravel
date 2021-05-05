/*
 * 188.cpp
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
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),  vector<int>(2*k, INT_MIN));
        for(int i=0; i<prices.size(); i++){
            for(int j=0; j<2*k; j++){
                if(j==0){
                    if(i==0){
                        dp[i][j]=-prices[i];
                    }else{
                        dp[i][j]=max(dp[i-1][j], -prices[i]);
                    }

                }else if(j%2==1&&i!=0){
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]+prices[i]);
                }else if(i!=0){
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]-prices[i]);
                }
            }
        }
        int res=0;
        if(dp.size()>=1)
        {
            for(int j=1; j<2*k; j=j+2){
                res=max(res, dp.back()[j]);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

