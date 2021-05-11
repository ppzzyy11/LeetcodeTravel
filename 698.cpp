/*
 * 698.cpp
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(const auto& num: nums){
            sum+=num;
        }
        if(sum%k!=0){
            return false;
        }
        for(const auto& num: nums){
            if(num>sum/k){
                return false;
            }
        }
        vector<int> sums(k, 0);

        return recur(sums, nums, 0, sum/k);

    }

    bool recur(vector<int>& sums, const vector<int>& nums, int idx, const int target){
        if(idx==nums.size()){
            for(const auto& sum: sums){
                if(sum!=target){
                    return false;
                }
            }
            return true;
        }

        for(int i=0; i<sums.size(); i++){
            sums[i]+=nums[idx];
            if(recur(sums, nums, idx+1, target)){
                return true;
            }
            sums[i]-=nums[idx];
        }
        return false;
    }


    bool
};







int main(){
    return 0;
}

