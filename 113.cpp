/*
 * 113.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(res, path, root, targetSum);
        return res;
    }

    void backtracking(vector<vector<int> >&res, vector<int>& path, TreeNode* node, int targetSum){
        if(node==NULL){
            return ;
        }
        if(node->left==NULL&&node->right==NULL){
            path.push_back(node->val);
            if(node->val==targetSum){
                res.push_back(path);
            }
            path.pop_back();
            return ;
        }
        path.push_back(node->val);
        targetSum-=node->val;
        if(node->left){
            backtracking(res, path, node->left, targetSum);
        }
        if(node->right){
            backtracking(res, path, node->right, targetSum);
        }

        path.pop_back();
    }
};





int main(){
    return 0;
}

