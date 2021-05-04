/*
 * 95.cpp
 * Copyright (C) 2021-05-04 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
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
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

    /**
     * generate BST with nodes [s, e]
     * return all possible ansners in vector
     */
    vector<TreeNode*> generate(int s, int e){
        vector<TreeNode*> res;
        if(s>e){
            return res;
        }
        if(s==e){
            res.push_back(new TreeNode(s));
            return res;
        }

        for(int val=s; val<=e; val++){
            TreeNode* node= new TreeNode(val);
            vector<TreeNode*> lefts=generate(s, val-1);
            vector<TreeNode*> rights=generate(val+1, e);
            if(lefts.size()!=0&&rights.size()!=0){
                for(auto left: lefts){
                    for(auto right: rights){
                        node->left=left;
                        node->right=right;
                        res.push_back(deepCopyTree(node));
                    }
                }
            }else if(lefts.size()!=0){
                for(auto left:lefts){
                    node->left=left;
                    res.push_back(deepCopyTree(node));
                }
            }else if(rights.size()!=0){
                for(auto right: rights){
                    node->right=right;
                    res.push_back(deepCopyTree(node));
                }
            }
            for(auto left: lefts){
                deleteTree(left);
            }
            for(auto right: rights){
                deleteTree(right);
            }
        }
        return res;
    }

    TreeNode* deepCopyTree(TreeNode* node){
        if(node==NULL){
            return NULL;
        }
        TreeNode* copy=new TreeNode(node->val);
        copy->left=deepCopyTree(node->left);
        copy->right=deepCopyTree(node->right);
        return copy;
    }

    void deleteTree(TreeNode* node){
        if(node==NULL){ return ; }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        return ;
    }
};







int main(){
    return 0;
}

