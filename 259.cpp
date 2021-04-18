/*
 * 259.cpp
 * Copyright (C) 2021-04-17 pzy <pzy@pzy-B250M-Wind>
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
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res=0;
        for(int i=0; i<nums.size(); i++){
            res+=helper(nums, i+1, nums.size()-1, target-nums[i]);
        }
        return res;
    }

    int helper(const vector<int>& nums, int s, int e, int target){
        int l=s, r= e;
        int res=0;
        while(l<r){
            int sum=nums[r]+nums[l];
            if(sum<target){
                //important, any [s-1, l, {l+1, l+2, ... r}]
                res+=r-l;
                l++;
            }else{
                r--;
            }

        }
        return res;

    }
};



/*
 * 0<=n<=300
 * 1. Brute Force. O(N^3)= 2.7 * 10^7. T.L.E.
 * 2. Tow pointers. Because this solution only return times so we can sort it mannuly.
 *
 */

int main(){
    return 0;
}

