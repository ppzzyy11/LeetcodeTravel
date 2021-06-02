/*
 * 208.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



class Trie {
    struct Node{
        vector<Node*> chlds;
        bool leaf;

        Node(){
            chlds.resize(26, NULL);
            leaf=false;
        }
    };

    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            int idx=word[i]-'a';
            if(node->chlds[idx]==NULL){
                node->chlds[idx]=new Node();
            }
            node=node->chlds[idx];
        }
        node->leaf=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            int idx=word[i]-'a';
            if(node->chlds[idx]==NULL){
                return false;
            }
            node=node->chlds[idx];
        }
        return node->leaf;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0; i<prefix.size(); i++){
            int idx=prefix[i]-'a';
            if(node->chlds[idx]==NULL){
                return false;
            }
            node=node->chlds[idx];
        }
        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */





int main(){
    return 0;
}

