/*
 * 86.cpp
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode();
        ListNode* bigger = new ListNode();
        ListNode* b=bigger, *s=smaller;

        while(head){
            if(head->val<x){
                s->next=new ListNode(head->val);
                s=s->next;
            }else{
                b->next=new ListNode(head->val);
                b=b->next;
            }
            head=head->next;
        }

        s->next=bigger->next;
        return smaller->next;
    }
};





int main(){
    return 0;
}

