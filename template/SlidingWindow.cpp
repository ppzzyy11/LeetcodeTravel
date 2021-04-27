/*
 * SlidingWindow.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int l=0, r=0;
        int res=0;
        while(r<nums.size()){
            product*=nums[r++];
            while(l<r&&product>=k){
                product/=nums[l];
                l++;
                //[l,r)
            }
            //[l,r)
            if(product<k){
                res+=r-l;
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

