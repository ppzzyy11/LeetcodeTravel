/*
 * 285.cpp
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL){
            return NULL;
        }
        stack<TreeNode*> st;
        while(root){
            st.push(root);
            root=root->left;
        }

        bool found=false;
        while(st.size()){
            TreeNode* top=st.top();
            if(found){
                return top;
            }
            st.pop();

            if(top==p){
                found=true;
            }

            TreeNode* node=top->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }

        return NULL;

    }
};





int main(){
    return 0;
}

