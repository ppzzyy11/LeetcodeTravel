/*
 * 651.cpp
 * Copyright (C) 2021-05-10 pzy <pzy@pzy-B250M-Wind>
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
public:
    int maxA(int n) {
        //minimal steps to get i As
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            dp[i]=max(i, dp[i-1]+1);
            for(int j=1; j<i-1; j++){
                //Ctrl+A from j, the chosen value is dp[j-1]
                dp[i]=max(dp[i], dp[j-1]*(i-j));
            }
        }
        return dp[n];
    }
};


int main(){
    return 0;
}

