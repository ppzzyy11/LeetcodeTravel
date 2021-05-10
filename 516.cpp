/*
 * 516.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }

        return recur(s, 0, n-1, dp);
    }

    int recur(const string& str, int s, int e, vector<vector<int> >& dp){
        if(s>e){
            return 0;
        }
        if(dp[s][e]!=0){
            return dp[s][e];
        }

        return dp[s][e]=max(str[s]==str[e]?recur(str, s+1, e-1, dp)+2:0, max(recur(str, s+1, e, dp), recur(str, s, e-1, dp)));

    }
};





int main(){
    return 0;
}

