/*
 * 298.cpp
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
    int longestConsecutive(TreeNode* root) {
        dfs(root, 0, INT_MIN);
        return maxLen;
    }
    int maxLen=0;

    int dfs(TreeNode* node, int len, int targetVal){
        if(node==NULL){
            return 0;
        }
        if(node->val==targetVal){
            len=len+1;
            dfs(node->left, len, targetVal+1);
            dfs(node->right, len, targetVal+1);
        }else{
            len=1;
            dfs(node->left, len,node->val+1 );
            dfs(node->right, len,node->val+1 );
        }
        maxLen=max(maxLen, len);
        return len;
    }
};





int main(){
    return 0;
}

