/*
 * 142.cpp
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;

        fast=fast->next;
        while(fast&&fast!=slow){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        if(fast==NULL){
            return NULL;
        }

        //fast==slow
        fast=head;
        slow=slow->next;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;


    }
};





int main(){
    return 0;
}

