/*
 * 106.cpp
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

struct TreeNode;

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* buildTree(const vector<int>& inorder, int l1, int r1, const vector<int>& postorder, int l2, int r2){
        if(l1>r1||l2>r2){
            return NULL;
        }
        if(l1==r1&&l2==r2){
            return new TreeNode(postorder[r2], NULL, NULL);
        }

        int m1=getIndex(inorder,l1,r1, postorder[r2]);
        int m2=m1-r1+r2;

        return new TreeNode(postorder[r2], buildTree(inorder, l1, m1-1, postorder, l2, m2-1), buildTree(inorder, m1+1, r1, postorder, m2, r2-1));
    }

    int getIndex(const vector<int>& inorder, int l, int r, int target){
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

