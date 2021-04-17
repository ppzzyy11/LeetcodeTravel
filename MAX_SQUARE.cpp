/*
 * 85.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
 *
 */

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    if(i==0||j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                    res=max(res, dp[i][j]*dp[i][j]);
                }
            }
        }
        return res;
    }
};






int main(){
    return 0;
}
