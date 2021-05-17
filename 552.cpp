/*
 * 552.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
    long MOD=1000000007;
public:
    int checkRecord(int n) {
        //f(n) =2*f(n-1)-f(n-4)
        vector<long> dp(n+1, 0);
        dp[0]=1;
        if(n==0){
            return 1;
        }
        dp[1]=2;
        if(n==1){
            return 3;
        }
        dp[2]=4;
        if(n==2){
            return 8;
        }
        dp[3]=7;
        if(n==3){
            return 19;
        }
        for(int i=4; i<=n ;i++){
            dp[i]=(2*dp[i-1]%MOD-dp[i-4]+MOD)%MOD;
        }

        long res=dp[n];
        for(int l=0; l<=n-1; l++){
            int r=n-1-l;
            res+=(dp[l]*dp[r]%MOD);
            res=res%MOD;
        }
        return  res;
    }
};





int main(){
    return 0;
}

