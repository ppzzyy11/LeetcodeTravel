/*
 * 98.cpp
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
    bool isValidBST(TreeNode* root) {

        long pre=INT_MIN-1l;
        //inorder
        stack<TreeNode*> st;
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        while(st.size()){
            TreeNode* top=st.top();
            st.pop();
            if(top->val<=pre){
                return false;
            }
            pre=top->val;
            if(top->right!=NULL){
                TreeNode* right=top->right;
                while(right!=NULL){
                    st.push(right);
                    right=right->left;
                }
            }
        }


        return true;
    }
};





int main(){
    return 0;
}

