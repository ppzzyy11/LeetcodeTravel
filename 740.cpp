/*
 * 740.cpp
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
    int deleteAndEarn(vector<int>& nums) {
        int maxV=0;
        for(const auto& num: nums){
            maxV=max(maxV, num);
        }

        vector<int> sum(maxV+1, 0);

        for(const auto& num: nums){
            sum[num]+=num;
        }

        return rob(sum);
    }

    int rob(const vector<int>& nums){
        vector<int> dp(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                dp[0]=nums[i];
            }else if(i==1){
                dp[1]=max(nums[0], nums[1]);
            }else{
                dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
            }
        }
        return dp.back();
    }
};





int main(){
    return 0;
}

