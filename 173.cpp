/*
 * 173.cpp
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



class BSTIterator {
    stack<TreeNode*> st;
    TreeNode* nil=NULL;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
        nil=new TreeNode(-1);
    }

    int next() {
        TreeNode* top=st.top();
        int res=top->val;
        st.pop();

        if(top->right){
            top=top->right;
            while(top){
                st.push(top);
                top=top->left;
            }
        }

        //delete top

        return res;
    }

    bool hasNext() {
        return st.size()!=0;
    }
};





int main(){
    return 0;
}

