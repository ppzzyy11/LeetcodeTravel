/*
 * 445.cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        return reverse(add(l1, l2));
    }

    ListNode* reverse(ListNode* node){
        if(node==NULL){
            return node;
        }
        ListNode* cur, *pre, *nxt;
        pre=NULL;
        cur=node;
        while(cur){
            nxt=cur->next;

            cur->next=pre;

            pre=cur;
            cur=nxt;
            if(nxt){
                nxt=nxt->next;
            }

        }

        return pre;

    }

    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* node=dummy;
        int add=0;

        while(l1||l2||add){
            node->next=new ListNode();
            node=node->next;

            node->val=(l1?l1->val:0)+(l2?l2->val:0)+add;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
            add=node->val/10;
            node->val%=10;
        }
        return dummy->next;

    }

};





int main(){
    return 0;
}

