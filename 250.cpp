/*
 * 250.cpp
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
    int ans=0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        dfs(root);
        return ans;

    }

    bool dfs(TreeNode* node){

        bool l=true;
        bool r=true;

        if(node->left!=NULL){
            l=dfs(node->left)&&node->val==node->left->val;

        }

        if(node->right!=NULL){
            r=dfs(node->right)&&node->val==node->right->val;
        }

        ans+=(l&&r);

        return l&&r;
    }


};





int main(){
    return 0;
}

