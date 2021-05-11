/*
 * 801.cpp
 * Copyright (C) 2021-05-11 pzy <pzy@pzy-B250M-Wind>
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
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<int>dp0(nums1.size(), INT_MAX);
        vector<int>dp1(nums2.size(), INT_MAX);

        for(int i=0; i<nums1.size(); i++){
            if(i==0){
                dp0[0]=0;
                dp1[0]=1;
                continue;
            }


            if(nums1[i-1]<nums1[i]&&nums2[i-1]<nums2[i]){
                dp0[i]=min(dp0[i-1], dp0[i]);
                // dp0[i]=min(dp1[i-1]+1, dp0[i]);

                // dp1[i]=min(dp0[i-1]+1, dp1[i]);
                dp1[i]=min(dp1[i-1]+1, dp1[i]);
            }
            if(nums1[i-1]<nums2[i]&&nums2[i-1]<nums1[i]){
                // dp0[i]=min(dp0[i], dp0[i-1]+1);
                dp0[i]=min(dp0[i], dp1[i-1]);
                dp1[i]=min(dp1[i], dp0[i-1]+1);
                // dp1[i]=min(dp1[i], dp1[i-1]+1);
            }
        }

        return min(dp0.back(), dp1.back());

    }
};





int main(){
    return 0;
}

