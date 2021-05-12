/*
 * 471.cpp
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
    int duplicatedLen(string s){
        return (s+s).find(s, 1);
    }

    int lenOfNum(int num){
        int res=0;
        while(num){
            res++;
            num=num/10;
        }
        return res;
    }
    string encode(string str) {
        int n=str.size();
        vector<vector<string> > dp(n, vector<string>(n, ""));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=str.substr(i,j-i+1);
            }
        }

        for(int len=3; len<=n; len++){
            for(int s=0; s+len<n; s++){
                int e=s+len-1;
                int subLen=duplicatedLen(str.substr(s, len+1));
                int rep =(len+1)/subLen;
                string substr=str.substr(s, subLen);
                if(subLen<len){
                    int repLen=lenOfNum(rep)+2+subLen;
                    if(repLen<dp[s][s+len].size()){
                        dp[s][s+len]=to_string(rep)+"["+dp[s][s+subLen-1]+"]";
                    }
                }

                for(int k=0; k<len; k++){
                    if(dp[s][s+len].size()>(dp[s][s+k].size()+dp[s+k+1][s+len].size())){
                        dp[s][s+len]=dp[s][s+k]+dp[s+k+1][s+len];
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};


//tried to design a memorization as [start_index][len]=repeated_times



int main(){
    Solution s;
    string str="aaaaaa";
    cout<<s.duplicatedLen(str);
    return 0;
}

