/*
 * 162.cpp
 * Copyright (C) 2021-04-15 pzy <pzy@pzy-B250M-Wind>
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
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int l=0, r=nums.size()-1;
        while(l+1<r){
            int m =(r-l)/2+l;
            if(nums[m]>nums[m+1]){
                r=m;
            }else{
                l=m;
            }
        }
        if((l==0&&nums[l]>nums[r])||(l!=0&&nums[l]>nums[l-1]&&nums[l]>nums[r])){
            return l;
        }
        if((r==nums.size()-1&&nums[r]>nums[l])||(r!=nums.size()-1&&nums[l]<nums[r]&&nums[r]>nums[r+1])){
            return r;
        }
        return -1;
    }
};



//首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值
//作者：guanpengchn
//链接：https://leetcode-cn.com/problems/find-peak-element/solution/hua-jie-suan-fa-162-xun-zhao-feng-zhi-by-guanpengc/
//来源：力扣（LeetCode）


int main(){
    return 0;
}

