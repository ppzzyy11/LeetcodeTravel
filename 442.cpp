/*
 * 442.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> rec;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            rec[nums[i]]++;
            if(rec[nums[i]]==2)
            {
                res.push_back(nums[i]);
            }

        }
        return res;
    }
};





int main(){
    return 0;
}

