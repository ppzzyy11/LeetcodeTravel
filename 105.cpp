/*
 * 105.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
 *
 */

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(const vector<int>&preorder,int l1, int r1, const vector<int>& inorder, int l2, int r2 ){
        if(l1>r1||l2>r2){
            return NULL;
        }
        if(l1==r1&&l2==r2){
            return new TreeNode(preorder[l1], NULL, NULL);
        }
        int m2=binarySearch(inorder, l2, r2, preorder[l1]);
        int m1=m2-l2+l1;

        return new TreeNode(preorder[l1], buildTree(preorder, l1+1, m1, inorder, l2,m2-1), buildTree(preorder, m1+1, r1, inorder, m2+1, r2));
    }

    //not increasing
    int binarySearch(const vector<int>& inorder, int l, int r, int target){
        for(int i=l; i<=r; i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }


};




int main(){
    return 0;
}


