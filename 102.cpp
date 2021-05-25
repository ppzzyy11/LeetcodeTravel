/*
 * 102.cpp
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);

        vector<int> tmp;
        while(que.size()){
            TreeNode* fnt=que.front();
            que.pop();
            if(fnt!=NULL){
                tmp.push_back(fnt->val);
                if(fnt->left){
                    que.push(fnt->left);
                }
                if(fnt->right){
                    que.push(fnt->right);
                }
            }else{
                res.push_back(tmp);
                tmp.resize(0);
                if(que.size()!=0){
                    que.push(NULL);
                }
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

