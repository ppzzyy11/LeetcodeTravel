/*
 * 82.cpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* tail=head;
        while(tail->next!=NULL&&tail->next->val==head->val){
            tail=tail->next;
        }
        if(tail==head){//no duplicate
            head->next=deleteDuplicates(head->next);
            return head;
        }else{
            return deleteDuplicates(tail->next);
        }
        return NULL;

    }
};





int main(){
    return 0;
}

