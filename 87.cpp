/*
 * 87.cpp
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
    //dp[i][j]
    vector<vector<vector<int>>> dp;
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        int n=s1.size();
        //-1 means not scramble, 0 means not accessing, 1 means scramble
        dp.resize(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

        return dfs(s1, 0, s2, 0, s1.size());


    }

    int dfs(const string& s1, int i,  const string& s2, int j, int len){
        //may out of memory
        if(dp[i][j][len]!=0){
            return dp[i][j][len];
        }
        if(s1.substr(i, len)==s2.substr(j, len)){
            return dp[i][j][len]=1;
        }
        if(!similar(s1, i, s2, j, len)){
            return dp[i][j][len]=-1;
        }


        for(int p=1; p<len; p++){
            if((dfs(s1,i, s2, j, p)==1)&&(1==dfs(s1,i+p, s2, j+p, len-p))){
                return dp[i][j][len]=1;
            }
            if(( dfs(s1, i, s2, j+len-p, p)==1)&&(dfs(s1, i+p, s2, j , len-p)==1)){
                return dp[i][j][len]=1;
            }
        }

        return dp[i][j][len]=-1;
    }

    bool similar(const string& s1, int i, const string& s2, int j, int len){
        vector<int> cnt(26,0);
        for(int l=0; l<len; l++){
            cnt[s1[i+l]-'a']++;
        }
        for(int l=0; l<len; l++){
            cnt[s2[j+l]-'a']--;
        }
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]!=0){
                return false;
            }
        }
        return true;
    }
};





int main(){
    return 0;
}

