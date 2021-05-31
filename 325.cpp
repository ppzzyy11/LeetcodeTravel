/*
 * 325.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        rec[0]=-1;
        int sum=0;
        int res=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(rec.count(sum-k)){
                res=max(res, i-rec[sum-k]);
            }
            if(rec.count(sum)==0){
                rec[sum]=i;
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

