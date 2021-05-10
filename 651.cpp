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
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            dp[i]=i;
        }

        //try C+A, C+C, C+V at the ith step
        for(int i=1; i<=n; i++){
            for(int j=i+2; j<=n; j++){
                dp[j]=max(dp[j], dp[j]+(j-i-1)*dp[i]);
            }
        }

        return dp.back();
    }
};


int main(){
    return 0;
}

