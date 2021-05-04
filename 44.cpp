/*
 * 44.cpp
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
            if(p[j]=='*'){
                dp[0][j+1]=dp[0][j];
            }
        }
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<p.size(); j++){
                if(s[i]==p[j]||p[j]=='?'){
                    dp[i+1][j+1]=dp[i][j];
                }else if(p[j]=='*'){
                    dp[i+1][j+1]=dp[i][j]|dp[i+1][j]|dp[i][j+1];

                }
            }
        }

        return dp.back().back();
    }
};
/*
 * ? for any character
 * * for any sequences of characters
 * examples:
 *
 *  a
 *  b
 *  false
 *
 *  a*
 *  a
 *  true
 *
 *  ""
 *  *
 *  true
 *
 *  if(s[i]==p[j]||p[j]=='?')
 *  dp[i+1][j+1]=dp[i][j];
 *
 *  if(p[j]=='*'){
 *  for empty
 *  dp[i+1][j+1]=dp[i+1][j];
 *  for any character
 *  dp[i+1][j+1]=dp[i][j];
 *  }
 *
"aa"
"a"
"aa"
"*"
"cb"
"?b"
"bc"
"c?"
"adceb"
"*a*b"
"acdcb"
"a*c?b"
 */





int main(){
    return 0;
}

