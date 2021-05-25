/*
 * 116.cpp
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
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }

        queue<Node*> que;
        que.push(root);
        que.push(NULL);

        vector<Node*> tmp;

        while(que.size()){
            Node* fnt=que.front();
            que.pop();
            if(fnt){
                tmp.push_back(fnt);
                if(fnt->left){
                    que.push(fnt->left);
                }
                if(fnt->right){
                    que.push(fnt->right);
                }
            }else{
                for(int i=0; i<tmp.size()-1; i++){
                    tmp[i]->next=tmp[i+1];
                }
                tmp.back()->next=NULL;
                tmp.resize(0);
                if(que.size()){
                    que.push(NULL);
                }
            }
        }
        return root;
    }
};





int main(){
    return 0;
}

