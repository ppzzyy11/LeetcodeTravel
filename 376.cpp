/*
 * 376.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 * Description:
 *
 *      To implement:
 *      How:
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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int res=1;

        vector<int> dp0(n, 1);//try to up
        vector<int> dp1(n, 1);//try to down
        for(int i=0; i<n; i++){
            //update dp0/1[i]
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i], dp0[j]+1);
                }
                if(nums[i]<nums[j]){
                    dp0[i]=max(dp0[i], dp1[j]+1);
                }
            }
            res=max(res, max(dp0[i], dp1[i]));
        }

        return res;
    }
};





int main(){
    return 0;
}

