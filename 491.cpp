/*
 * 491.cpp
 * Copyright (C) 2021-05-27 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>path;
        dfs(0, INT_MIN, nums, res, path);
        return res;
    }

    void dfs(int idx, int last, const  vector<int>& nums, vector<vector<int>>& res, vector<int>& path){
        if(idx==nums.size()){
            if(path.size()>=2){
                res.push_back(path);
            }
            return ;
        }

        if(nums[idx]>=last){
            path.push_back(nums[idx]);
            dfs(idx+1, nums[idx], nums, res, path);
            path.pop_back();
        }

        if(nums[idx]!=last){
            dfs(idx+1, last, nums, res, path );
        }
    }
};





int main(){
    return 0;
}

