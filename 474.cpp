/*
 * 474.cpp
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp [i][j] i个1，j个0可以最多有多少个subset
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int k=0; k<strs.size(); k++){
            pair<int,int> cnts=cnt(strs[k]);
            for(int i=m; i>=0; i--){
                for(int j=n; j>=0; j--){
                    if(i-cnts.first>=0&&j-cnts.second>=0)
                        dp[i][j]=max(dp[i][j], dp[i-cnts.first][j-cnts.second]+1);
                }
            }
        }
        return dp[m][n];

    }

    pair<int,int> cnt(const string& str){
        int cnt0=0;
        int cnt1=0;
        for(auto& ch: str){
            if(ch=='0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        return make_pair(cnt0, cnt1);
    }
};





int main(){
    return 0;
}

