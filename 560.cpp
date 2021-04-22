/*
 * 560.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int sum=0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            res+=cnt[sum-k];
            cnt[sum]++;

        }

        return res;
    }
};





int main(){
    return 0;
}

