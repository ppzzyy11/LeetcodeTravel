/*
 * 264.cpp
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
    int nthUglyNumber(int n) {
        vector<int> dp(n, INT_MAX);
        dp[0]=1;
        int i2=0, i3=0, i5=0;
        for(int i=1; i<dp.size(); i++){
            int res=getMax(dp, i2, i3, i5);
            if(dp[i2]*2==res){
                dp[i]=dp[i2]*2;
                i2++;}
            if(dp[i3]*3==res){
                dp[i]=dp[i3]*3;
                i3++;
            }
            if(dp[i5]*5==res){
                dp[i]=dp[i5]*5;
                i5++;
            }
        }
        return dp[n-1];
    }

    int getMax(const vector<int>& dp, int i2, int i3, int i5){
        int res=-1;
        if(dp[i2]*2<=dp[i3]*3&&dp[i2]*2<=dp[i5]*5){
            res=2*dp[i2];
        }
        if(dp[i3]*3<=dp[i2]*2&&dp[i3]*3<=dp[i5]*5){
            res=3*dp[i3];
        }
        if(dp[i5]*5<=dp[i2]*2&&dp[i5]*5<=dp[i3]*3){
            res=5*dp[i5];
        }
        return res;
    }
};





int main(){
    return 0;
}

