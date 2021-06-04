/*
 * 215.cpp
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
            bool operator()(const int a, const int b){
                return a>b;
            }
    };
public:
    int findKthLargest(vector<int>& nums, int k) {
        //k min heap, pop the minimal numers until there are k elements left

        priority_queue<int, vector<int>, cmp> pq;
        for(const int& num: nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};





int main(){
    return 0;
}

