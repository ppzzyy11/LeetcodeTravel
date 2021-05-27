/*
 * 99.cpp
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
public:
    void recoverTree(TreeNode* root) {
        vector<int> travel(0,0);

        if(root==NULL){
            return ;
        }

        inorder(root, travel);
        vector<int> sor=travel;
        sort(sor.begin(), sor.end());
        vector<int> num;
        for(int i=0; i<travel.size(); i++){
            if(sor[i]!=travel[i]){
                num.push_back(sor[i]);
            }
        }
        inorder2(root, num);

    }

    void inorder(TreeNode* node, vector<int>& travel){
        if(node==NULL){
            return ;
        }
        inorder(node->left, travel);
        travel.push_back(node->val);
        inorder(node->right, travel);
    }

    void inorder2(TreeNode* node, const vector<int>& num){
        if(node==NULL){
            return ;
        }
        if(node->val==num[0]){
            node->val=num[1];
        }else if(node->val==num[1]){
            node->val=num[0];
        }
        inorder2(node->left, num);
        inorder2(node->right, num);
    }

};





int main(){
    return 0;
}

