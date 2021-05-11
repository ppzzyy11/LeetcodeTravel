/*
 * 790.cpp
 * Copyright (C) 2021-05-11 pzy <pzy@pzy-B250M-Wind>
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
    const int MOD=1000000007;
public:
    int numTilings(int n) {
        vector<long> dp(n+1, 0);
        if(n==1){
            return 1;
        }
        dp[1]=1;

        if(n==2){
            return 2;
        }
        dp[2]=2;

        dp[3]=5;

        for(int i=4; i<=n; i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%MOD;
        }

        return dp[n];

    }
};





int main(){
    return 0;
}

