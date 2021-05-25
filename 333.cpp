/*
 * 333.cpp
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
    int largestBSTSubtree(TreeNode* root) {

        bst[NULL]=true;
        smallest[NULL]=INT_MAX;
        biggest[NULL]=INT_MIN;
        nodes[NULL]=0;

        dfs(root);

        return nodes[ans];
    }

    unordered_map<TreeNode*, bool> bst;
    unordered_map<TreeNode*, int> smallest;
    unordered_map<TreeNode*, int> biggest;
    unordered_map<TreeNode*, int> nodes;

    TreeNode* ans=NULL;
    //return whether BST
    //return largets node
    //return smallest node
    //return number of nodes
    void dfs(TreeNode* node){
        if(bst.count(node)){
            return ;
        }
        int num=1;
        dfs(node->left);
        dfs(node->right);


        //largets
        biggest[node]=max(node->val, max(biggest[node->left], biggest[node->right]));
        smallest[node]=min(node->val, min(smallest[node->left], smallest[node->right]));
        nodes[node]=nodes[node->left]+nodes[node->right]+1;

        //bst
        if(bst[node->left]&&bst[node->right]&&biggest[node->left]<node->val&&smallest[node->right]>node->val){
            bst[node]=true;
            if(ans==NULL){
                ans=node;
            }else{
                if(nodes[node]>nodes[ans]){
                    ans=node;
                }
            }
        }
        return ;
    }
};





int main(){
    return 0;
}

