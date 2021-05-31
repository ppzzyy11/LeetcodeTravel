/*
 * 347.cpp
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


bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first>p2.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(const int& num: nums){
            cnt[num]++;
        }

        //cnt number
        vector<pair<int, int>> heap;
        for(auto it=cnt.begin(); it!=cnt.end(); it++){
            int num=it->first;
            int cnt=it->second;

            heap.push_back(make_pair(cnt, num));
            push_heap(heap.begin(), heap.end(), cmp);

            if(heap.size()>k){
                pop_heap(heap.begin(), heap.end(), cmp);
                heap.pop_back();
            }
        }

        vector<int> res;
        while(heap.size()!=0){
            res.push_back(heap[0].second);
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};





int main(){
    return 0;
}

