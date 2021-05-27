/*
 * 124.cpp
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
    int maxPathSum(TreeNode* root) {
        travel(root);
        return res;
    }

    int res=INT_MIN;

    //return the maximum of a child and the node
    int travel(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int l=travel(node->left);
        int r=travel(node->right);
        res=max(res, node->val+(l>0?l:0)+(r>0?r:0));
        return max(0, node->val+(max(l>0?l:0, r>0?r:0)));
    }
};





int main(){
    return 0;
}

