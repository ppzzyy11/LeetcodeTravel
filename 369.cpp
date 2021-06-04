/*
 * 369.cpp
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
    ListNode* plusOne(ListNode* head) {
        head=reverse(head);
        head->val++;
        ListNode* node=head;
        int add=0;
        while(node||add){
            node->val+=add;
            add=node->val/10;
            node->val%=10;
            if(add&&node->next==NULL){
                node->next=new ListNode();
            }
            node=node->next;
        }

        return reverse(head);

    }

    ListNode* reverse(ListNode* node){
        ListNode* cur, *pre, *nxt;
        cur=node;;
        pre=NULL;
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

};





int main(){
    return 0;
}

