/*
 * 230.cpp
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root){
            st.push(root);
            root=root->left;
        }

        while(st.size()){
            TreeNode* top=st.top();
            st.pop();

            k--;
            if(k==0){
                return top->val;
            }

            top=top->right;
            while(top){
                st.push(top);
                top=top->left;
            }
        }

        return -1;



    }
};





int main(){
    return 0;
}

