/*
 * 611.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        for(int k=nums.size()-1; k>=2; k--){
            int l=0, r=k-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[k]){
                    res+=r-l;
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};


class Solution1 {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int idx= binarySearch(nums, j+1, nums.size()-1, nums[i]+nums[j]);
                if(idx!=-1){
                    res+=idx-j;
                }
            }
        }
        return res;

    }


    int binarySearch(const vector<int>& nums, int l, int r, int target){
        if(l<0||l>=nums.size()||r<0||r>=nums.size()) return -1;
        while(l+1<r){
            int m=(r-l)/2+l;

            if(nums[m]<target){
                l=m;
            }else{
                r=m;
            }
        }
        if(nums[r]<target){
            return r;
        }
        if(nums[l]<target){
            return l;
        }


        return -1;
    }
};





int main(){
    return 0;
}

