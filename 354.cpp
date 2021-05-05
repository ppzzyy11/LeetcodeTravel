/*
 * 354.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
                [](const vector<int>& nums1, const vector<int>& nums2){
                if(nums1[0]!=nums2[0]){
                return nums1[0]<nums2[0];
                }
                return nums1[1]<nums2[1];
                });

        int n=envelopes.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }

        int res=0;
        for(int i=0; i<n; i++){
            res=max(res, dp[i]);
        }

        return res;
    }
};





int main(){
    return 0;
}

