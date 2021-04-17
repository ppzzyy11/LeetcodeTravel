/*
 * 216.cpp
 * Copyright (C) 2021-04-16 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        recur(res, path,0, 1, k, n);
        return res;
    }

    void recur(vector<vector<int>>& res, vector<int>& path,int sum, int start, const int& k, const int& n){
        if(path.size()==k){
            if(sum==n){
                res.push_back(path);
            }
            return ;
        }
        if(sum>n){
            return ;
        }
        if(start>9||start<0){
            return ;
        }
        recur(res, path, sum, start+1, k, n);
        path.push_back(start);
        recur(res, path, sum+start, start+1, k, n);
        path.pop_back();
    }
};





int main(){
    return 0;
}

