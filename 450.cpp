/*
 * 450.cpp
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
    TreeNode* deleteNode(TreeNode* node, int key) {
        if(node==NULL){
            return NULL;
        }
        if(node->val==key){
            if(node->left==NULL&&node->right==NULL){
                delete node;
                return NULL;
            }
            if(node->right!=NULL){
                TreeNode* des=node->right;
                while(des->left!=NULL){
                    des=des->left;
                }
                node->val=des->val;
                node->right=deleteNode(node->right, des->val);
            }else{
                TreeNode* des=node->left;
                while(des->right!=NULL){
                    des=des->right;
                }
                node->val=des->val;
                node->left=deleteNode(node->left, des->val);
            }
            return node;
        }else if(node->val>key){
            node->left=deleteNode(node->left, key);
        }else{
            node->right=deleteNode(node->right, key);
        }
        return node;
    }
};





int main(){
    return 0;
}

