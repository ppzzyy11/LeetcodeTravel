/*
 * 646.cpp
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



struct cmp {
    bool operator() (const vector<int>& p1,const vector<int>& p2) {
        if(p1[0]!=p2[0]){
            return p1[0]<p2[0];
        }
        return p1[1] < p2[1];         // first 小的先弹出
    }
};
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(),cmp());
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(valid(pairs[j], pairs[i])){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        int res=0;
        for(auto d:dp){
            res=max(res, d);
        }

        return res;
    }

    bool valid(const vector<int>& p1, const vector<int>& p2){
        if(p1[1]<p2[0]){
            return true;
        }
        return false;
    }
};




int main(){
    return 0;
}

