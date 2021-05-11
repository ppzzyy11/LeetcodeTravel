/*
 * 650.cpp
 * Copyright (C) 2021-05-11 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        //minimal steps to get i As
        vector<int> dp(n+1, 0);
        for(int i=0; i<=n; i++){
            dp[i]=i;
        }

        for(int i=1; i<=n; i++){
            for(int j=2; j<i; j++){
                if(i%j==0){
                    //dp[i] is equal to try to get j As to j*(i/j), the *i needs dp[i/j] steps
                    dp[i]=min(dp[i], dp[j]+dp[i/j]);
                }
            }
        }

        return dp[n];
    }
};





int main(){
    return 0;
}

