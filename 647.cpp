/*
 * 647.cpp
 * Copyright (C) 2021-05-10 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 * Description:
 *
 *      To implement:
 *      How:
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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;



class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            //odd
            for(int len=0;i-len>=0&&i+len<n; len++ ){
                if(s[i-len]==s[i+len]){
                    dp[i-len][i+len]=true;
                    res++;
                }else{
                    break;
                }
            }
            for(int len=0; i-len>=0&&i+len+1<n; len++){
                if(s[i-len]==s[i+len+1]){
                    dp[i-len][i+len+1]=true;
                    res++;
                }else{
                    break;
                }
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

