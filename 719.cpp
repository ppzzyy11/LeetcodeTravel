/*
 * 719.cpp
 * Copyright (C) 2021-05-03 pzy <pzy@pzy-B250M-Wind>
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
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        //binary search
        int l=0, r=nums.back()-nums[0];
        while(l<r){
            int m=(l+r)/2;
            if(count(nums, m)>=k){
                r=m;
            }else{
                l=m+1;
            }
        }
        return r;
    }


    //sliding window
    int count(const vector<int>& nums, int upper){
        int res=0;
        int l=0, r=0;
        while(r<nums.size()){
            //[l,r)
            while(l<r&&nums[r]-nums[l]>upper){
                l++;
            }
            res+=r-l;
            r++;
        }
        return res;
    }
};





int main(){
    return 0;
}

