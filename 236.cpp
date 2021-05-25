/*
 * 236.cpp
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p, q);
        return ans;
    }

    TreeNode* ans=NULL;

    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return make_pair(false, false);
        }
        pair<bool, bool> l =dfs(root->left, p, q);
        pair<bool, bool> r =dfs(root->right, p, q);

        pair<bool, bool> res=make_pair((l.first||r.first||p==root), (l.second||r.second||q==root));
        if( res.first==true&&res.second==true&&ans==NULL){
            ans=root;
        }
        return res;

    }

};





int main(){
    return 0;
}

