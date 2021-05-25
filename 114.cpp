/*
 * 114.cpp
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
    void flatten(TreeNode* root) {
        TreeNode* node=root;
        while(node){
            TreeNode* left=node->left;
            if(left!=NULL){
                TreeNode* right=node->right;
                TreeNode* lr=node->left;
                while(lr->right!=NULL){
                    lr=lr->right;
                }
                lr->right=right;
                node->right=left;
                node->left=NULL;
            }
            node=node->right;
        }

    }

};





int main(){
    return 0;
}

