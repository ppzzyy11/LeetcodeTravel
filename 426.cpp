/*
 * 426.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node* last, *first;
public:

    void dfs(Node* node){
        if(node==NULL){
            return ;
        }
        dfs(node->left);

        if(last!=NULL){
            last->right=node;
            node->left=last;
        }
        last=node;

        if(first==NULL){
            first=node;
        }

        dfs(node->right);

    }
    Node* treeToDoublyList(Node* root) {
        last=first=NULL;
        if(root==NULL){
            return root;
        }
        dfs(root);
        first->left=last;
        last->right=first;
        return first;
    }
};





int main(){
    return 0;
}

