/*
 * 514.cpp
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
public:
    int findRotateSteps(string ring, string key) {
        int m=key.size();
        int n=ring.size();

        unordered_map<char, vector<int> > idx;
        for(int i=0; i<n; i++){
            char ch=ring[i];
            idx[ch-'a'].push_back(i);
        }

        //(i-1)th key,
        vector<vector<int> >dp(m+1, vector<int>(n, INT_MAX));
        dp[0][0]=0;
        for(int i=1; i<=m; i++){
            vector<int> pre;
            for(int j=0; j<n; j++){
                if(dp[i-1][j]!=INT_MAX){
                    pre.push_back(j);
                }
            }
            //pre is


            //cur is next char's possible index in ring
            const vector<int>& cur=idx[key[i-1]-'a'];
            for(int j=0; j<cur.size(); j++){
                int k=cur[j];
                for(int l=0; l<pre.size(); l++){
                    dp[i][k]=min(dp[i][k], dp[i-1][pre[l]]+getMinLen(n,pre[l],k)+1);
                }
            }
        }

        int res=INT_MAX;
        for(int i=0; i<n; i++){
            res=min(res, dp[m][i]);
        }
        return res;

    }

    int getMinLen(int n, int i, int j){
        return min(abs(i-j),min(abs(i-n-j), abs(i+n-j)));
    }
};





int main(){
    return 0;
}

