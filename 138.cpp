/*
 * 138.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* rtn=NULL;
        if(mp.count(head)!=NULL){
            rtn=mp[head];
        }else{
            mp[head]=rtn=new Node(head->val);
            rtn->next=copyRandomList(head->next);
            rtn->random=copyRandomList(head->random);
        }


        return rtn;
    }
};





int main(){
    return 0;
}

