/*
 * 61.cpp
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int len=0;
        ListNode* tmp=head;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        k=k%len;
        if(k==0){
            return head;
        }
        ListNode* fast=head, *slow=head;
        while(k-->0){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* new_head=slow->next;
        slow->next=NULL;
        fast->next=head;
        return new_head;
    }

};





int main(){
    return 0;
}

