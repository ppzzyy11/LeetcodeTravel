/*
 * 152.cpp
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
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int maxPro=nums[0],minPro=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                maxPro=minPro=nums[0];
            }else if(nums[i]==0){
                maxPro=minPro=0;
            }else {
                int nxt_maxPro=max(nums[i], max(maxPro*nums[i], minPro*nums[i]));
                int nxt_minPro=min(nums[i], min(maxPro*nums[i], minPro*nums[i]));
                maxPro=nxt_maxPro;
                minPro=nxt_minPro;
            }

            res=max(res, maxPro);
        }
        return res;
    }
};





int main(){
    return 0;
}

