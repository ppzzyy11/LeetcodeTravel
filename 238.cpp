/*
 * 238.cpp
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
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<=1){
            return nums;
        }
        int cnt0=0;
        int product=1;
        for(auto num:nums){
            if(num==0){
                cnt0++;
            }else {
                product*=num;
            }
        }
        vector<int> res(nums.size(), 0);
        for(int i=0; i<res.size(); i++){
            if(cnt0>=2){
                res[i]=0;
            }else if(cnt0==1){
                if(nums[i]==0){
                    res[i]=product;
                }else{
                    res[i]=0;
                }
            }else{
                res[i]=product/nums[i];
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

