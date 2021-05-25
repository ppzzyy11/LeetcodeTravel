/*
 * 437.cpp
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> cnt;
        cnt[0]=1;
        int ans=0;
        dfs(root, ans, cnt, 0, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int& ans, unordered_map<int, int>& cnt, int sum, const int & targetSum){
        if(root==NULL){
            return ;
        }
        sum+=root->val;
        if(cnt[sum-targetSum]>0){
            ans+=cnt[sum-targetSum];
        }

        cnt[sum]++;
        dfs(root->left, ans, cnt, sum, targetSum);
        dfs(root->right, ans, cnt, sum, targetSum);
        cnt[sum]--;

        return ;

    }
};





int main(){
    return 0;
}

