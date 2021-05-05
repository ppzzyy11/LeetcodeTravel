/*
 * 213.cpp
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
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(nums.size()-1, 0);
        vector<int> dp1(nums.size()-1, 0);
        //rober the first house
        for(int i=0; i<nums.size()-1; i++){
            if(i==0){
                dp[i]=nums[i];
            }else if(i==1){
                dp[i]=max(nums[0], nums[1]);
            }else{
                dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
            }
        }
        for(int i=1; i<nums.size(); i++){
            if(i==1){
                dp1[i-1]=nums[i];
            }else if(i==2){
                dp1[i-1]=max(nums[1], nums[2]);
            }else{
                dp1[i-1]=max(dp1[i-3]+nums[i], dp1[i-2]);
            }
        }
        return max(dp.back(), dp1.back());
    }
};





int main(){
    return 0;
}

