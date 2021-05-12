/*
 * 813.cpp
 * Copyright (C) 2021-05-12 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        //
        vector<vector<double> >dp(n, vector<double>(k+1, 0));
        vector<int> prefix(n, 0);
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            prefix[i]=sum;
        }

        for(int j=1; j<=k; j++){
            for(int i=0; i<n; i++){
                if(j==1){
                    dp[i][1]=getAve(prefix, 0, i);
                }else{
                    for(int k=1; k<=i+2-j; k++){
                        dp[i][j]=max(dp[i][j], dp[i-k][j-1]+getAve(prefix, i-k+1, i));
                    }

                }
            }
        }

        return dp[n-1][k];
    }

    double getAve(const vector<int>& prefix, int s, int e){
        double sum=prefix[e]-(s==0?0:prefix[s-1]);
        return sum/(e-s+1.0);
    }
};





int main(){
    return 0;
}

