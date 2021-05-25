/*
 * 199.cpp
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }

        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);

        while(que.size()){
            res.push_back(que.front()->val);
            while(que.front()!=NULL){
                TreeNode* fnt=que.front();
                que.pop();
                if(fnt->right){
                    que.push(fnt->right);
                }
                if(fnt->left){
                    que.push(fnt->left);
                }
            }
            que.pop();
            if(que.size()){
                que.push(NULL);
            }
        }

        return res;
    }
};





int main(){
    return 0;
}

