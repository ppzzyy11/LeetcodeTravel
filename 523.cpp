/*
 * 523.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> rec;
        long pre=0;
        long sum=0;
        for(auto num: nums){
            pre=sum;
            sum+=num;
            sum=sum%k;
            if(rec.count(sum)){
                return true;
            }else {
                rec.insert(pre);
            }
        }

        return false;
    }
};





int main(){
    return 0;
}

