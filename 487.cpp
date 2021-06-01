/*
 * 487.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> cnt(2, 0);

        int res=0;
        int l=0, r=0;
        while(r<nums.size()){
            cnt[nums[r]]++;

            while(cnt[0]>1){
                cnt[nums[l++]]--;
            }

            res=max(r-l+1, res);
            r++;
        }

        return res;

    }

};





int main(){
    return 0;
}

