/*
 * 220.cpp
 * Copyright (C) 2021-06-05 pzy <pzy@pzy-B250M-Wind>
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> se;
        for(int i=0; i<nums.size(); i++){
            auto it = se.lower_bound(max(nums[i], INT_MIN + t) - t);
            if(it!=se.end()&&(*it)<=min(nums[i], INT_MAX-t)+t){
                return true;
            }
            se.insert(nums[i]);
            if(i>=k){
                se.erase(se.find( nums[i-k] ));
            }
        }
        return false;
    }
};





int main(){
    return 0;
}

