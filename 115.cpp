/*
 * 115.cpp
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
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(!possible(s, t)){
            return 0;
        }
        if(s==t){
            return 1;
        }
        // - optimize space complexity
        vector<vector<double>> dp(s.size()+1, vector<double>(t.size()+1, 0));
        dp[0][0]=1;
        for(int i=0; i<s.size(); i++){
            dp[i][0]=1;
        }
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<t.size(); j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]+=dp[i][j];
                }
            }
            for(int j=0; j<t.size(); j++){
                dp[i+1][j+1]+=dp[i][j+1];
            }
        }
        return dp.back().back();
    }

    bool possible(const string& str1, const string& str2){
        if(str1.size()<str2.size()){
            return false;
        }
        vector<int> cnt(256,0);
        for(auto& ch: str1){
            cnt[ch]++;
        }
        for(auto& ch: str2){
            cnt[ch]--;
        }
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]<0){
                return false;
            }
        }
        return true;
    }
};





int main(){
    return 0;
}

