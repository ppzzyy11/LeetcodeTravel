/*
 * 10.cpp
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
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0]=true;
        for(int j=0; j<p.size(); j++){
            if(j!=0&&p[j]=='*'){
                dp[0][j+1]=dp[0][j+1]|dp[0][j-1];
            }
        }
        //edge cases
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<p.size(); j++){
                if(s[i]==p[j]||p[j]=='.'){
                    //match
                    dp[i+1][j+1]=dp[i][j]|dp[i+1][j+1];
                }else if(j!=0&&p[j]=='*'){
                    //p[j-1]*, p[j-1] repreats for 0 or many times.
                    dp[i+1][j+1]=dp[i+1][j+1]
                        |dp[i+1][j-1];//p[j-1] repreat for 0 times

                        if(p[j-1]==s[i]||p[j-1]=='.'){
                            dp[i+1][j+1]=dp[i+1][j+1]
                                |dp[i][j+1];//repreat for 1 time
                        }
                }else{
                    //not match
                    //
                }
            }
        }
        return dp.back().back();
    }
};





int main(){
    return 0;
}

