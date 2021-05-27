/*
 * 272.cpp
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> travel(0, 0);
        inorder(root, travel);

        vector<int> res;
        int l=0, r=travel.size()-1;
        while(l+1<r){
            int m=(l+r)/2;
            if(travel[m]>target){
                r=m;
            }else{
                l=m;
            }
        }


        while(k-->0){
            if(r>=travel.size()){
                res.push_back(travel[l--]);
            }else if(l<0){
                res.push_back(travel[r++]);
            }else{
                if(abs(target-travel[l])>abs(target-travel[r])){
                    res.push_back(travel[r++]);
                }else{
                    res.push_back(travel[l--]);
                }
            }
        }

        return res;

    }

    void inorder(TreeNode* node, vector<int>& travel){
        if(node==NULL){
            return ;
        }
        inorder(node->left, travel);
        travel.push_back(node->val);
        inorder(node->right, travel);
    }
};





int main(){
    return 0;
}

