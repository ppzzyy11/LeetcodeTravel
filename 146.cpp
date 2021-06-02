/*
 * 146.cpp
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

using namespace std;





class LRUCache {
struct Node{
    Node* prv;
    Node* nxt;
    int val;
};
    Node* tail, *head;
    unordered_map<int, Node*> kv;
    unordered_map<Node*, int> vk;
    int n;
    int c;
public:
    LRUCache(int capacity) {
        c=capacity;
        n=0;
        tail=new Node();
        head=new Node();
        head->nxt=tail;
        tail->prv=head;
    }

    int get(int key) {
        if(kv.count(key)){
            //move key to the first position after head;
            Node* node=kv[key];

            //move node out of list
            node->prv->nxt=node->nxt;
            node->nxt->prv=node->prv;

            //move after the head
            head->nxt->prv=node;
            node->nxt=head->nxt;

            head->nxt=node;
            node->prv=head;

            return kv[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(kv.count(key)){
            Node* node=kv[key];
            node->val=value;

            //move out
            node->prv->nxt=node->nxt;
            node->nxt->prv=node->prv;

            //move forward
            node->nxt=head->nxt;
            head->nxt->prv=node;

            node->prv=head;
            head->nxt=node;
        }else{

            if(c==n){
                //upgrade the last node
                Node* last= tail->prv;
                int last_key=vk[last];

                vk.erase(vk.find(last));
                kv.erase(kv.find(last_key));

                last->val=value;

                kv[key]=last;
                vk[last]=key;

                //move out
                last->prv->nxt=tail;
                tail->prv=last->prv;

                //move forward
                last->nxt=head->nxt;
                head->nxt->prv=last;

                last->prv=head;
                head->nxt=last;

            }else{
                //insert new node
                Node* node= new Node();
                node->val=value;

                //insert after head
                Node* nxt=head->nxt;
                node->nxt=nxt;
                nxt->prv=node;

                head->nxt=node;
                node->prv=head;


                //upgrade kv and vk
                kv[key]=node;
                vk[node]=key;

                n++;
            }

        }

    }
};






int main(){
    return 0;
}

