/*
 * 239.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //cnt
        unordered_map<int, int> cnt;
        //priority current maximum
        priority_queue<int> pq;

        //sliding window
        //l, r
        int r=0;
        while(r<k){
            cnt[nums[r]]++;
            if(cnt[nums[r]]==1){
                pq.push(nums[r]);
            }
            r++;
        }

        vector<int> res;
        res.push_back(pq.top());
        for(int i=k; i<nums.size(); i++){
            //push
            cnt[nums[i]]++;
            if(cnt[nums[i]]==1){
                pq.push(nums[i]);
            }

            //pop
            cnt[nums[i-k]]--;
            while(pq.size()&&cnt[pq.top()]==0){
                pq.pop();
            }

            res.push_back(pq.top());

        }

        return res;
    }
};





int main(){
    return 0;
}

