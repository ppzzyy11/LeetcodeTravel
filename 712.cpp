/*
 * 712.cpp
 * Copyright (C) 2021-05-11 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int minimumDeleteSum(string s1, string s2) {
        int m =s1.size();
        int n=s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0]=0;

        for(int i=1; i<=m; i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int j=1; j<=n; j++){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=min(dp[i-1][j-1], dp[i][j]);
                }
                dp[i][j]=min(dp[i][j],min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]));
            }
        }

        return dp[m][n];
    }
};





int main(){
    return 0;
}

