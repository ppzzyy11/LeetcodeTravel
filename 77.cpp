/*
 * 77.cpp
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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(n, false);
        backtracking(res, path, n, k, visited );
        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& path, int n, int k,  vector<bool>& visited){
        if(path.size()==k){
            res.push_back(path);
            return ;
        }

        for(int i=(path.size()==0?1:path.back()); i<=n; i++){
            if(visited[i]==false){
                visited[i]=true;
                path.push_back(i);
                backtracking(res, path, n, k, visited);
                path.pop_back();
                visited[i]=false;
            }
        }
    }
};





int main(){
    return 0;
}

