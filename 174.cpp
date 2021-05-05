/*
 * 174.cpp
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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size()+1, vector<int>(dungeon[0].size()+1, INT_MAX));
        dp[dungeon.size()][dungeon[0].size()-1]=dp[dungeon.size()-1][dungeon[0].size()]=1;
        for(int i=dungeon.size()-1; i>=0; i--){
            for(int j=dungeon[i].size()-1; j>=0; j--){
                dp[i][j]=max(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};





int main(){
    return 0;
}

