/*
 * 133.cpp
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

using namespace std;



class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> src2des;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(src2des.count(node)){
            return src2des[node];
        }

        Node* newNode= new Node(node->val);
        src2des[node]=newNode;
        for(Node* n: node->neighbors){
            newNode->neighbors.push_back(cloneGraph(n));
        }


        return newNode;

    }
};





int main(){
    return 0;
}

