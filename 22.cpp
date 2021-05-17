/*
 * 22.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path="";
        backtracking(res, path, n, 0);
        return res;
    }

    void backtracking(vector<string>& res, string path, int n, int left){
        if(left==0&&n==0){
            res.push_back(path);
            return ;
        }

        //generate '('
        if(left<n) {
            backtracking(res, path+'(',n, left+1 );

        }
        //generate ')'
        if(left>0&&left<=n){
            backtracking(res, path+')', n-1, left-1);
        }

    }

};





int main(){
    return 0;
}

