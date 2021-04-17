/*
 * 81.cpp
 * Copyright (C) 2021-04-13 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
 *
 */

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n= nums.size();
        int p =0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                p=i+1;
                break;
            }
        }
        //p is the index of the minimal number

        int l=0, r=nums.size()-1;
        while(l+1<r){
            while(l+1<r&&nums[getIndex(l,p,n)]==nums[getIndex(l+1, p, n)]){
                l++;
            }
            while(l<r-1&&nums[getIndex(r, p, n)]==nums[getIndex(r-1, p, n)]){
                r--;
            }
            int m = (r-l)/2+l;

            int idx = getIndex(m, p, n);
            if(nums[idx]==target){
                return true;
            }else if(nums[idx]>target){
                r=m;
            }else if(nums[idx]<target){
                l=m;
            }
        }
        return nums[getIndex(l,p,n)]==target||nums[getIndex(r, p, n)]==target;
    }

    int getIndex(int i, int p, int n){
        return (i+p)%n;
    }
};






int main(){
    return 0;
}
