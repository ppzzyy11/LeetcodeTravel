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
    class cmp{
        public:
            bool operator()(int a, int b){
                return a>b;
            }
    };
    priority_queue<int> maxH;
    unordered_map<int, int> maxCnt;
    priority_queue<int, vector<int>, cmp> minH;
    unordered_map<int, int> minCnt;

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0; i<k; i++){
            pushMax(nums[i]);
            pushMin(nums[i]);
        }

        int idx=k;
        while(idx<nums.size()){
            pushMax(nums[idx]);
            pushMin(nums[idx]);

            popMax(nums[idx-k]);
            popMin(nums[idx-k]);

            if(abs(maxH.top()-minH.top())<=t){
                return true;
            }

            idx++;
        }

        return false;
    }

    void pushMin(int num){
        minH.push(num);
        minCnt[num]++;
    }

    void popMin(int num){
        minCnt[num]--;
        while(minH.size()&&minCnt[minH.top()]==0){
            minH.pop();
        }
    }

    void pushMax(int num){
        maxH.push(num);
        maxCnt[num]++;
    }

    void popMax(int num){
        maxCnt[num]--;
        while(maxH.size()&&maxCnt[maxH.top()]==0){
            maxH.pop();
        }
    }
};





int main(){
    return 0;
}

