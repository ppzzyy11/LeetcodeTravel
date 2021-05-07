/*
 * 91.cpp
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
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 1);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                if(i==0||s[i-1]<='0'||s[i-1]>='3'){
                    return 0;
                }
                // s[i] must combine with s[i-1]
                dp[i+1]=dp[i-1];

            }else if(i!=0&&((s[i-1]=='1'&&s[i]>='0'&&s[i]<='9')||(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6'))){
                //d[i] i is alone, d[i-1]: i is with i-1
                dp[i+1]=dp[i]+dp[i-1];
            }else{
                dp[i+1]=dp[i];
            }
        }
        return dp.back();
    }
};





int main(){
    return 0;
}

