/*
 * 918.cpp
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
public:
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        vector<int> r(A.size(), 0);
        for(int i=0; i<A.size(); i++){
            if(i==0){
                dp[i]=A[i];
                continue;
            }
            dp[i]=max(dp[i-1], 0)+A[i];
        }

        int sum=0;
        for(int i=A.size()-1; i>=0; i--){
            sum+=A[i];
            if(i==A.size()-1){
                r[i]=A[i];
                continue;
            }
            r[i]=max(r[i+1],sum);
        }

        int res=INT_MIN;
        sum=0;
        for(int i=0; i<A.size(); i++){
            sum+=A[i];
            res=max(res, dp[i]);
            res=max(res, sum+(i+2<A.size()?r[i+2]:0));
            // res=max(res, dp[i]+(i+2<A.size()?r[i+2]:0));
        }

        return res;
    }
};





int main(){
    return 0;
}

