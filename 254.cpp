/*
 * 254.cpp
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
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(res, path, 2, n);
        res.pop_back();
        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& path, int s, int target){
        if(target==1){
            res.push_back(path);
            return ;
        }

        for(int i=s; i*i<=target; i++){
            if(target%i==0){
                int j=target/i;
                path.push_back(i);
                backtracking(res, path, i, j);
                path.pop_back();
            }
        }
        path.push_back(target);
        backtracking(res, path, s, 1);
        path.pop_back();

    }
};





int main(){
    return 0;
}

