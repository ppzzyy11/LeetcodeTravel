/*
 * 403.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> val2idx;
        int n=stones.size();
        if(stones[1]!=1){
            return false;
        }
        for(int i=0; i<n; i++){
            val2idx[stones[i]]=i;
        }

        vector<set<int>> dp(n, set<int>());
        dp[1].insert(1);

        for(int i=0; i<n; i++){
            for(auto it=dp[i].begin(); it!=dp[i].end(); it++){
                int jump=(*it);
                if(jump-1>0&&val2idx.count(stones[i]+jump-1)){
                    dp[val2idx[stones[i]+jump-1]].insert(jump-1);
                }
                if(jump>0&&val2idx.count(stones[i]+jump)){
                    dp[val2idx[stones[i]+jump]].insert(jump);
                }
                if(jump+1>0&&val2idx.count(stones[i]+jump+1)){
                    dp[val2idx[stones[i]+jump+1]].insert(jump+1);
                }
            }
        }

        return dp.back().size()!=0;
    }
};





int main(){
    return 0;
}

