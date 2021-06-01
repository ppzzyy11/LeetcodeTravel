/*
 * 147.cpp
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0, NULL);
        dummy->next=NULL;
        ListNode* next=head->next;
        while(head){
            next=head->next;
            ListNode* tmp=dummy;
            while(tmp!=NULL&&(tmp->next!=NULL&&tmp->next->val<=head->val)){
                tmp=tmp->next;
            }
            ListNode* tmpNxt=tmp->next;

            tmp->next=head;
            head->next=tmpNxt;
            head=next;
        }

        return dummy->next;
    }
};





int main(){
    return 0;
}

