/*
 * 449.cpp
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



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        queue<TreeNode*> que;
        que.push(root);
        string res="";
        while(que.size()){
            TreeNode* fnt=que.front();
            que.pop();
            if(fnt!=NULL){
                res+=num2str(fnt->val)+SPLIT;
                que.push(fnt->left);
                que.push(fnt->right);
            }else{
                res+=NUL+SPLIT;
            }
        }
        if(res.size()&&res[res.size()-1]==SPLIT){
            res.pop_back();
        }
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }

                vector<TreeNode*> nodes;
        int s=0,e=0;
        while(s<data.size()){
            e=s;
            while(e<data.size()&&data[e]!=SPLIT){
                e++;
            }
            string substr=data.substr(s, e-s);
            if(substr==NUL){
                nodes.push_back(NULL);
            }else{
                nodes.push_back(new TreeNode(str2num(substr)));
            }
            s=e+1;
        }

        int i=0, j=1;
        while(j<nodes.size()){
            nodes[i]->left=nodes[j++];
            nodes[i]->right=nodes[j++];
            i++;
            while(nodes[i]==NULL){
                i++;
            }
        }

        return nodes[0];
    }

    int str2num(string num){
        int res=0;
        for(int i=0; i<num.size(); i++){
            res=res*MOD+(int)num[i]-ADD;
        }
        return res;
    }

    int MOD=100;
    int ADD=10;
    char SPLIT='\2';
    string NUL="\1";

    string num2str(int num){
        string res="";
        while(num){
            res+=(char)(num%MOD+ADD);
            num/=MOD;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};





int main(){
    return 0;
}

