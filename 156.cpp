/*
 * 156.cpp
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* right=NULL, *parent=NULL;
        while(root!=NULL){
            TreeNode* left=root->left;
            root->left=right;
            right=root->right;
            root->right=parent;

            parent=root;
            root=left;

        }
        return parent;

    }


};





int main(){
    return 0;
}

