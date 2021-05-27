/*
 * 211.cpp
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


class TrieNode{
    public:
        bool leaf;
        vector<TrieNode*> children;
        TrieNode(){
            leaf=false;
            children.resize(26, NULL);
        }
};

class WordDictionary {
    TrieNode* root=NULL;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node=root;
        for(const char& ch: word){
            int idx=ch-'a';
            if(node->children[idx]==NULL){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->leaf=true;
    }

    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, TrieNode* node){
        if(node==NULL){
            return false;
        }
        if(word.size()==0){
            return node->leaf;
        }
        for(int i=0; i<word.size(); i++){
            char ch=word[i];
            if(ch=='.'){
                string substr=word.substr(i+1);
                for(TrieNode* child: node->children){
                    if(search(substr, child)){
                        return true;
                    }
                }
                return false;
            }else{
                int idx=ch-'a';
                node=node->children[idx];
                if(node==NULL){
                    return false;
                }
            }

        }
        return node->leaf;
    }

};





int main(){
    return 0;
}

