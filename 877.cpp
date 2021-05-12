/*
 * 877.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int> > dp;
public:
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        for(const auto& pile: piles){
            sum+=pile;
        }
        int n=piles.size();
        dp.resize(n, vector<int>(n ,-1));
        return win(piles, 0, n-1)>=(sum+1)/2;
    }

    int win(const vector<int>& piles, int s, int e){
        if(s>e||s<0||e>=piles.size()){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        if(s==e){
            return dp[s][e]=piles[e];
        }

        return dp[s][e]=max(piles[s]+min(win(piles, s+1, e-1), win(piles,s+2, e)), min(win(piles, s+1, e-1), win(piles, s, e-2))+piles[e]);
    }
};





int main(){
    return 0;
}

