/*
 * 276.cpp
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
    int numWays(int n, int k) {
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            if(i==0){
                dp[i]=k;
            }else if(i==1){
                dp[i]=k*k;
            }else{
                dp[i]=(dp[i-2]+dp[i-1])*(k-1);
            }
        }
        return dp[n-1];
    }
};





int main(){
    return 0;
}

