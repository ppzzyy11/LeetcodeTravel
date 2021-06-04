/*
 * 328.cpp
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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* l1, *l2;
        l1=l2=NULL;
        ListNode* node1, *node2;
        node1=node2=NULL;
        while(head){
            if(l1==NULL){
                node1=l1=head;
            }else{
                node1->next=head;
                node1=node1->next;
            }
            head=head->next;

            if(head){
                if(l2==NULL){
                    node2=l2=head;
                }else{
                    node2->next=head;
                    node2=node2->next;
                }
                head=head->next;
            }
        }
        node1->next=l2;
        if(node2)
        node2->next=NULL;
        return l1;
    }
};





int main(){
    return 0;
}

