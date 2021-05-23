/*
 * 2.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int add){
        if(l1==NULL&&l2==NULL&&add==0){
            return NULL;
        }
        int num=add;
        if(l1!=NULL){
            num+=l1->val;
        }
        if(l2!=NULL){
            num+=l2->val;
        }
        ListNode* node = new ListNode(num%10);
        if(num>=10||l1||l2)
            node->next=addTwoNumbers(l1?l1->next:NULL,l2?l2->next:NULL, num/10);
        return node;
    }
};





int main(){
    return 0;
}

