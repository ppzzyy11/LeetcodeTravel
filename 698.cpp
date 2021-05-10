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
        for(auto& num: nums){
            sum+=num;
        }
        if(sum%k!=0){
            return false;
        }
        int n=nums.size();

        vector<bool> visited(n,false);
        return possible(nums, 0, 0, k, visited, sum/k);

    }


    bool possible(const vector<int>& nums, int idx,int sum,int k, vector<bool>& visited, const int target ){
        //dp memorization
        if(sum>target){
            return false;
        }
        if(sum==target){
            k--;
            if(k==0){
                return true;
            }
        }
        if(idx==nums.size()){
            return false;
        }

        bool res=false;
        if(visited[idx]==false){
            visited[idx]=true;
            res=res|possible(nums, idx+1, sum+nums[idx], k, visited, target);
            visited[idx]=false;
        }
        res=res|possible(nums, idx+1, sum, k, visited, target);
        return res;
    }
};





int main(){
    return 0;
}

