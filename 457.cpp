/*
 * 457.cpp
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
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){

            if(nums[i]==0){
                continue;
            }
            //loop
            int idx=i;

            while(nums[idx]!=0)
            {
                int num = nums[idx];
                nums[idx]=0;
                int nxt_idx=(idx+num+nums.size())%nums.size();
                if(nxt_idx==idx){
                    break;
                }
                if(nums[nxt_idx]==0){
                    return true;
                }
                idx=nxt_idx;
            }

        }
        return false;
    }
};





int main(){
    return 0;
}

