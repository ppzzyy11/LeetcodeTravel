/*
 * 432.cpp
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



class AllOne {
    struct Node{
        Node* prv, *nxt;
        int cnt;
        Node(int cnt=0){
            prv=nxt=NULL;
            this->cnt=cnt;
        }
    };

    struct NodeBase{
        NodeBase* prv, *nxt;
        Node* head, *tail;
        int cnt;
        int numOfNodes;
        NodeBase(int cnt){
            prv=nxt=NULL;
            head=new Node(cnt);
            tail=new Node(cnt);

            head->nxt=tail;
            tail->prv=head;

            this->cnt=cnt;
            numOfNodes=0;
        }

    };

    NodeBase *head, *tail;
    //never delete
    unordered_map<int, NodeBase*> cnt2base;
    unordered_map<string, Node*> str2node;
    unordered_map<Node*, string> node2str;
public:
    /** Initialize your data structure here. */
    AllOne() {
        head=new NodeBase(0);
        tail=new NodeBase(INT_MAX);
        head->nxt=tail;
        tail->prv=head;
        cnt2base[0]=head;
        cnt2base[INT_MAX]=tail;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(str2node.count(key)==0){
            str2node[key]=new Node(1);
            node2str[str2node[key]]=key;
            if(cnt2base.count(1)==0){
                NodeBase* cnt1=new NodeBase(1);
                // head cnt1 head->nxt
                cnt1->nxt=head->nxt;
                head->nxt->prv=cnt1;

                cnt1->prv=head;
                head->nxt=cnt1;
                cnt2base[1]=cnt1;
            }
            insertNode2NodeBase(str2node[key], cnt2base[1]);
        }else{
            Node* node=str2node[key];
            int pre_cnt=node->cnt;
            removeNode(node, cnt2base[pre_cnt]);

            node->cnt++;
            int cur_cnt=node->cnt;
            if(cnt2base.count(cur_cnt)==0){
                //insert new NodeBase
                NodeBase* pre_base=cnt2base[pre_cnt];
                NodeBase* new_base=new NodeBase(cur_cnt);
                cnt2base[cur_cnt]=new_base;

                pre_base->nxt->prv=new_base;
                new_base->nxt=pre_base->nxt;

                pre_base->nxt=new_base;
                new_base->prv=pre_base;
            }
            if(cnt2base[pre_cnt]->numOfNodes==0){
                removeNodeBase(cnt2base[pre_cnt]);
            }
            NodeBase* base=cnt2base[cur_cnt];
            insertNode2NodeBase(node, base);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(str2node.count(key)==0){
            return ;
        }else{
            Node* node=str2node[key];
            int pre_cnt=node->cnt;
            node->cnt--;
            int cur_cnt=node->cnt;

            removeNode(node, cnt2base[pre_cnt]);
            if(cur_cnt==0){
                node2str.erase(node2str.find(node));
                str2node.erase(str2node.find(key));
            }else if(cnt2base.count(cur_cnt)==0){
                NodeBase* pre_base=cnt2base[pre_cnt];
                NodeBase* new_base=new NodeBase(cur_cnt);
                cnt2base[cur_cnt]=new_base;

                //new_base pre_base
                pre_base->prv->nxt=new_base;
                new_base->prv=pre_base->prv;

                new_base->nxt=pre_base;
                pre_base->prv=new_base;
            }
            if(cnt2base[pre_cnt]->numOfNodes==0){
                removeNodeBase(cnt2base[pre_cnt]);
            }

            insertNode2NodeBase(node, cnt2base[cur_cnt]);
        }

    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        NodeBase* base=tail->prv;
        Node* node=base->head->nxt;
        return node2str[node];
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        NodeBase* base=head->nxt;
        Node* node=base->head->nxt;
        return node2str[node];

    }

    void insertNode2NodeBase(Node* node, NodeBase* base){
        if(node!=NULL&&base!=NULL){
            Node* head=base->head;
            node->nxt=head->nxt;
            head->nxt->prv=node;
            node->prv=head;
            head->nxt=node;

            base->numOfNodes++;
        }

    }

    Node* removeNode(Node* node, NodeBase* base){
        if(node==NULL||base==NULL||node->prv==NULL||node->nxt==NULL){
            return NULL;
        }

        //node->prv node node->nxt
        // node->prv node->nxt
        node->prv->nxt=node->nxt;
        node->nxt->prv=node->prv;

        node->nxt=node->prv=NULL;
        base->numOfNodes--;


        return node;

    }

    bool removeNodeBase(NodeBase* base){
        if(base->numOfNodes==0){
            base->prv->nxt=base->nxt;
            base->nxt->prv=base->prv;
            cnt2base.erase(cnt2base.find(base->cnt));
            return true;
        }
        return false;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */





int main(){
    return 0;
}

