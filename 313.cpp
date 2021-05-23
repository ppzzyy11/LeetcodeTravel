/*
 * 313.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> dp(1, 1);
        for(int i=0; i<n; i++){
            int minValue=INT_MAX;
            for(int j=0; j<primes.size(); j++){
                minValue=min(minValue, primes[j]*dp[idx[j]]);
            }
            for(int j=0; j<primes.size(); j++){
                if(minValue==primes[j]*dp[idx[j]]){
                    idx[j]++;
                }
            }
            dp.push_back(minValue);
        }

        return dp[n-1];
    }
};





int main(){
    return 0;
}

