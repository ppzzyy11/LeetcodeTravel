/*
 * 72.cpp
 * Copyright (C) 2021-05-04 pzy <pzy@pzy-B250M-Wind>
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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i=0; i<word1.size(); i++){
            dp[i+1][0]=i+1;
        }
        for(int j=0; j<word2.size(); j++){
            dp[0][j+1]=j+1;
        }

        for(int i=0; i<word1.size(); i++){
            for(int j=0; j<word2.size(); j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    dp[i+1][j+1]=min(dp[i][j], min(dp[i][j+1], dp[i+1][j]))+1;
                }
            }
        }
        return dp.back().back();
    }
};





int main(){
    return 0;
}

