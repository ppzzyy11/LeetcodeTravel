/*
 * 97.cpp
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
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        //waste space
        vector<vector<vector<bool>>> dp(s1.size()+1, vector<vector<bool>>(s2.size()+1, vector<bool>(s3.size()+1, false)));
        dp[0][0][0]=true;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]==s3[i])
                dp[i+1][0][i+1]=true;
            else
                break;
        }

        for(int j=0; j<s2.size(); j++){
            if(s2[j]==s3[j])
                dp[0][j+1][j+1]=true;
            else
                break;
        }

        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                //k is calulated by i/j, so there is no need to use a 3-dimension array, use a 2-dimension matrix instead.
                int k=i+j+2-1;
                if(s1[i]==s3[k]){
                    dp[i+1][j+1][k+1] = dp[i+1][j+1][k+1]| dp[i][j+1][k];
                }
                if(s2[j]==s3[k]){
                    dp[i+1][j+1][k+1] = dp[i+1][j+1][k+1]| dp[i+1][j][k];
                }
            }
        }


        return dp.back().back().back();
    }
};





int main(){
    return 0;
}

