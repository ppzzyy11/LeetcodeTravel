/*
 * 379.cpp
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



class PhoneDirectory {
    struct Node{
        Node* prv;
        Node* nxt;
        int val;
    };
    unordered_map<int, Node*> h_empty;
    unordered_map<int, Node*> h_used;
    Node* l_e_h;
    Node* l_e_t;
    Node* l_u_h;
    Node* l_u_t;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        l_e_h=new Node();
        l_e_t=new Node();

        l_e_h->nxt=l_e_t;
        l_e_t->prv=l_e_h;

        l_u_h=new Node();
        l_u_t=new Node();

        l_u_h->nxt=l_u_t;
        l_u_t->prv=l_u_h;

        for(int i=0; i<maxNumbers; i++){
            Node* node=new Node();
            node->val=i;
            insertNode(l_e_h, node);
        }

    }

    void insertNode(Node* head, Node* node){
        if(node!=NULL){
            head->nxt->prv=node;
            node->nxt=head->nxt;

            node->prv=head;
            head->nxt=node;
            if(head==l_u_h) {
                h_used[node->val]=node;
            }else{
                h_empty[node->val]=node;
            }
        }

    }

    void remove(Node* head, int value){
        Node* node;
        if(head==l_u_h){
            //remove from used
            if(h_used.count(value)){
                node=h_used[value];
                //move out of list
                node->prv->nxt=node->nxt;
                node->nxt->prv=node->prv;
                h_used.erase(h_used.find(value));

                //insert into empty
                h_empty[value]=node;
                l_e_h->nxt->prv=node;
                node->nxt=l_e_h->nxt;
                l_e_h->nxt=node;
                node->prv=l_e_h;
            }
        }else{
            //remove from empty
            if(h_empty.count(value)){
                node=h_empty[value];
                //move out of list
                node->prv->nxt=node->nxt;
                node->nxt->prv=node->prv;
                h_empty.erase(h_empty.find(value));

                //insert
                h_used[value]=node;
                l_u_h->nxt->prv=node;
                node->nxt=l_u_h->nxt;
                l_u_h->nxt=node;
                node->prv=l_u_h;
            }
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(h_empty.size()==0){
            return -1;
        }
        int val=l_e_h->nxt->val;
        remove(l_e_h, val);
        return val;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return h_empty.count(number)!=0;
    }

    /** Recycle or release a number. */
    void release(int number) {
        if(h_used.count(number)!=0){
            remove(l_u_h, number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */





int main(){
    return 0;
}

