/*
 * 279.cpp
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
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        //DP why 6370 TLE? but 10000, 9999 pass
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            if(i*i<=n){
                dp[i*i]=1;
            }
            if(dp[i]!=INT_MAX)
                continue;
            for(int j=1; j<=i/2+1; j++){
                if(i<j*j){
                    break;
                }
                //use j*j rather than j, reduce time to O(N^0.5)
                dp[i]=min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp.back();
    }

};





int main(){
    return 0;
}

