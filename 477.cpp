/*
 * 477.cpp
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
    int totalHammingDistance(vector<int>& nums) {
        int res=0;

        vector<vector<int>> cnt(32, vector<int>(2, 0));

        for(int i=0; i<nums.size(); i++){
            int num=nums[i];
            for(int k=31; k>=0; k--){
                int j=(num&(1<<k))!=0?1:0;
                res+=cnt[k][(j+1)%2];
                cnt[k][j]++;
            }
        }

        return res;

    }
};





int main(){
    return 0;
}

