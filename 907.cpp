/*
 * 907.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    long MOD = 1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int> > dp(arr.size(), vector<int>(arr.size(),0));
        for(int len=0; len<arr.size(); len++){
            for(int i=0; i+len<arr.size(); i++){
                if(len==0){
                    dp[i][i+len]=arr[i];
                }else{
                    dp[i][i+len]=min(dp[i][i+len], min(dp[i][i+len-1], arr[i+len]));
                }
            }
        }

        int res=0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i; j<arr.size(); j++){
                res+=dp[i][j];
                res=res%MOD;
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

