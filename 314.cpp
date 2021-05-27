/*
 * 314.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> res;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==NULL){
            return res;
        }
        TreeNode* node=root;
        TreeNode* NIL=NULL;
        int l=0;
        int r=0;
        dfs(root,0, l, r);
        res.resize(l+r+1);
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, l));
        que.push(make_pair(NIL, l));
        while(que.size()){
            pair<TreeNode*, int> fnt=que.front();
            que.pop();

            TreeNode* node=fnt.first;
            int v=fnt.second;
            if(node==NIL){
                if(que.size())
                que.push(fnt);
            }else{
                res[v].push_back(node->val);
                if(node->left){
                    que.push(make_pair(node->left, v-1));
                }
                if(node->right){
                    que.push(make_pair(node->right, v+1));
                }
            }
        }
        return res;
    }

    void dfs(TreeNode* node, int v, int& l, int & r){
        if(node==NULL){
            return ;
        }
        l=max(l, -v);
        r=max(r, v);
        dfs(node->left, v-1, l, r);
        dfs(node->right, v+1, l, r);
    }

};





int main(){
    return 0;
}

