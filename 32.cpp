/*
 * 32.cpp
 * Copyright (C) 2021-04-13 pzy <pzy@pzy-B250M-Wind>
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
#include <stack>

using namespace std;




class Solution {
    public:
        int longestValidParentheses(string s) {
            vector<int> dp(s.size(), 0);
            for(int i=0; i<s.size(); i++){
                if(s[i]=='('){
                    continue;
                }
                if(s[i]==')'){
                    int j=i-1;
                    while(j>=0&&dp[j]!=0){
                        j=j-dp[j];
                    }
                    if(j>=0&&s[j]=='('){
                        dp[i]=i-j+1;
                    }
                }
            }

            int res=0;
            int idx=dp.size()-1;
            int tmp_len=0;
            while(idx>=0){
                if(dp[idx]!=0){
                    tmp_len+=dp[idx];
                    idx=idx-dp[idx];
                }else{
                    res=max(res, tmp_len);
                    tmp_len=0;
                    idx--;
                }
            }
            res=max(res, tmp_len);
            return res;

        }
};

//cases analysis
//(()
//002

//)()()
//00202

//)(())()
//0002402

//(()(()
//002002

//(()())
//002024


int main(){
    return 0;
}
