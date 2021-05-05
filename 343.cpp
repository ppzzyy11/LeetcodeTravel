/*
 * 343.cpp
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
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[0]=0;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                dp[i]=max(dp[i], max(dp[j]*dp[i-j],max(dp[j]*(i-j), j*(i-j))));
            }
        }
        return dp.back();
    }
};





int main(){
    return 0;
}

