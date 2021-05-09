/*
 * 446.cpp
 * Copyright (C) 2021-05-08 pzy <pzy@pzy-B250M-Wind>
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long,long long>> dp(n);//i is index of the end, j is difference
        long long ans=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff=(long long)nums[i]-(long long)nums[j];
                long long sum=0;
                if(dp[j].count(diff)){
                    sum=dp[j][diff];
                }
                dp[i][diff]+=sum+1;
                ans+=sum;

            }
        }
        return ans;

    }
};





int main(){
    return 0;
}

