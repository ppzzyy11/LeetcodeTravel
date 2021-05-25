/*
 * 366.cpp
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<int> tmp;
        vector<vector<int>> res;
        while(dfs(root, tmp)){
            res.push_back(tmp);
            tmp.resize(0);
        }
        res.push_back(tmp);

        return res;

    }

    TreeNode* dfs(TreeNode* node, vector<int>& tmp){
        if(node==NULL){
            return NULL;
        }
        if(node->left==NULL&&node->right==NULL){
            tmp.push_back(node->val);
            return NULL;
        }
        node->left=dfs(node->left, tmp);
        node->right=dfs(node->right, tmp);
        return node;
    }
};





int main(){
    return 0;
}

