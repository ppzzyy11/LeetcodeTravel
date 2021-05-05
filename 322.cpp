/*
 * 322.cpp
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
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(long i=0; i<dp.size(); i++){
            if(dp[i]!=INT_MAX)
            for(auto coin: coins){
                if(i+coin<dp.size()){
                    dp[i+coin]=min(dp[i+coin], dp[i]+1);
                }
            }
        }
        return dp.back()==INT_MAX?-1:dp.back();
    }
};





int main(){
    return 0;
}

