/*
 * 494.cpp
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
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> pre(2001, 0);
        vector<int> cur(2001, 0);
        cur[1000]=1;
        for(int i=0; i<nums.size(); i++){
            pre=cur;
            for(int i=0; i<cur.size(); i++){
                cur[i]=0;
            }
            for(int j=0; j<pre.size(); j++){
                if(pre[j]!=0){
                    cur[j-nums[i]]+=pre[j];
                    cur[j+nums[i]]+=pre[j];
                }
            }

        }


        return cur[target+1000];

    }
};





int main(){
    Solution s;
    vector<int> nums({1,1,1,1,1});
cout<<s.findTargetSumWays(nums, 3);
    return 0;
}

