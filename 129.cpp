/*
 * 129.cpp
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
    int sumNumbers(TreeNode* root) {
        return backtracking(root, 0);
    }

    int backtracking(TreeNode* node, int sum){
        if(node==NULL){
            return 0;
        }
        if(node->left==NULL&&node->right==NULL){
            return sum*10+node->val;
        }
        sum=sum*10+node->val;
        return backtracking(node->left, sum)+backtracking(node->right, sum);
    }
};





int main(){
    return 0;
}

