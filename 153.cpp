/*
 * 153.cpp
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
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l+1<r){
            int m=(r-l)/2+l;
            if(nums[m]>nums[l]&&nums[r]>nums[m]){
                return nums[l];
            }else if(nums[l]<nums[m]&&nums[l]>nums[r]){
                l=m;
            }else{
                r=m;
            }
        }

        if(l==r){
            return nums[l];
        }
        if((l==0&&nums[l]<nums[r])||(l!=0&&nums[l]<nums[l-1]))
        {
            return nums[l];
        }
        return nums[r];
    }
};





int main(){
    return 0;
}

