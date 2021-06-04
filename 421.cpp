/*
 * 421.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    struct Trie{
        //left is 0, right is 1
        Trie *left, *right;
    };
    Trie* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root= new Trie();
        int res=0;
        for(int i=1; i<nums.size(); i++){
            insert(nums[i-1]);
            res=max(res, check(nums[i]));
        }

        return res;

    }

    int check(int num){
        Trie* node=root;
        int res=0;
        for(int k=30; k>=0; k--){
            if((num&(1<<k))){
                if(node->left){//1^0
                    res|=(1<<k);
                    node=node->left;
                }else{//1^1
                    res|=(0<<k);
                    node=node->right;
                }
            }else{//(num&(1<<k))==0
                if(node->right){//0^1
                    res|=(1<<k);
                    node=node->right;
                }else{
                    //node->left 0^0
                    res|=(0<<k);
                    node=node->left;
                }
            }
        }
        return res;
    }


    void insert(int num){
        Trie* node=root;
        for(int k=30; k>=0; k--){
            if((num&(1<<k))==0){
                if(node->left==NULL){
                    node->left=new Trie();
                }
                node=node->left;
            }else{
                if(node->right==NULL){
                    node->right=new Trie();
                }
                node=node->right;
            }
        }
    }
};





int main(){
    return 0;
}

