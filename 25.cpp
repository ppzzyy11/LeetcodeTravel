/*
 * 25.cpp
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1){
            return head;
        }
        //find tail
        ListNode* tail=head;
        for(int i=0; i<k; i++){
            if(tail==NULL){
                return head;
            }
            if(i!=k-1)
            tail=tail->next;
        }
        //next of tail
        ListNode* next=tail->next;

        tail->next=NULL;
        //rtn is tail
        ListNode* rtn =reverse(head);
        //head->next is next
        head->next=reverseKGroup(next, k);
        return rtn;
    }

    ListNode* reverse(ListNode* head){
        ListNode* cur=head, *pre=NULL, *nxt;
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

