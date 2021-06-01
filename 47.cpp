/*
 * 47.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        backtracking(res, path, nums, visited);

        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& path, const vector<int>& nums, vector<bool>& visited){
        if(path.size()==nums.size()){
            res.push_back(path);
            return ;
        }

        for(int i=0; i<visited.size(); i++){
            if(visited[i]==false){
                if(i!=0&&nums[i-1]==nums[i]&&visited[i-1]==false){
                    continue;
                }
                visited[i]=true;
                path.push_back(nums[i]);
                backtracking(res, path, nums, visited);
                path.pop_back();
                visited[i]=false;
            }
        }

    }
};





int main(){
    return 0;
}

