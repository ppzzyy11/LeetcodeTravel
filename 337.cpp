/*
 * 337.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include <utility>
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res= help(root);
        return max(res.first, res.second);
    }

    //res.first is res without rober this node
    //res.second is  after robering this node
    pair<int, int> help(TreeNode* node){
        if(node==NULL){
            return make_pair(0, 0);
        }
        pair<int, int> left=make_pair(0, 0);
        if(node->left!=NULL){
            left=help(node->left);
        }
        pair<int, int> right=make_pair(0, 0);
        if(node->right!=NULL){
            right=help(node->right);
        }
        return make_pair(max(left.first, left.second)+max(right.first, right.second), node->val+left.first+ right.first);

    }


};





int main(){
    return 0;
}

