/*
 * 209.cpp
 * Copyright (C) 2021-04-16 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int sum=0;
        int res=INT_MAX;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>=target){
                res=min(res, r-l+1);
                sum-=nums[l++];
            }
            r++;
        }
        return res==INT_MAX?0:res;
    }
};





int main(){
    return 0;
}

