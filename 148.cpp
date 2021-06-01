/*
 * 148.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head, *slow_p=NULL;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
            slow=slow->next;
        }

        ListNode* list1=head;
        ListNode* list2=slow->next;
        slow->next=NULL;


        list1=sortList(list1);
        list2=sortList(list2);
        return merge(list1, list2);

    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }

        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;

        while(l1||l2){
            if(l1&&l2){
                if(l1->val>l2->val){
                    cur->next=l2;
                    l2=l2->next;
                }else{
                    cur->next=l1;
                    l1=l1->next;
                }
            }else if(l1){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }

            cur=cur->next;
            cur->next=NULL;
        }

        return dummy->next;


    }
};





int main(){
    return 0;
}

