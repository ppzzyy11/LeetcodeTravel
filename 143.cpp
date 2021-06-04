/*
 * 143.cpp
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
    void reorderList(ListNode* head) {
        //split into two lists
        ListNode* l1=NULL, *l2=NULL;
        ListNode* node1=l1, *node2=l2;
        node1=head;
        node2=head;
        while(node2->next&&node2->next->next){
            node2=node2->next->next;
            node1=node1->next;
        }
        l1=head;
        l2=node1->next;
        node1->next=NULL;

        //reverse the list 2
        if(l2){
            node2=l2->next;
            node1=l2;

            while(node2){
                ListNode* nxt=node2->next;
                node2->next=node1;
                node1=node2;
                node2=nxt;
            }
            l2->next=NULL;
            l2=node1;
        }

        //merge list1 and list2
        node1=l1->next;
        node2=l2;
        head=l1;


        while(node1||node2){
            if(node2){
                l1->next=node2;
                node2=node2->next;
                l1=l1->next;
            }
            if(node1){
                l1->next=node1;
                node1=node1->next;
                l1=l1->next;
            }
        }

    }
};





int main(){
    return 0;
}

