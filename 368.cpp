/*
 * 368.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n, 1);
        vector<int> pre(n, -1);//previous index
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(len[i]<=len[j]){
                        len[i]=len[j]+1;
                        pre[i]=j;
                    }
                }
            }
        }

        vector<int> res;
        int start_idx=0;
        for(int i=0; i<n; i++){
            if(len[i]>len[start_idx]){
                start_idx=i;
            }
        }

        while(start_idx>=0){
            res.push_back(nums[start_idx]);
            start_idx=pre[start_idx];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};





int main(){
    return 0;
}

