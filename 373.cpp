/*
 * 373.cpp
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
    class cmp{
        public:
            bool operator()(const vector<int>& nums1, const vector<int>& nums2){
                return nums1[0]+nums1[1]>nums2[0]+nums2[1];
            }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(const int& num1: nums1){
            for(const int& num2: nums2){
                pq.push({num1, num2});
            }
        }


        vector<vector<int>> res;
        while(res.size()<k){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};





int main(){
    return 0;
}

