/*
 * 92.cpp
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }

        ListNode* nxt=head->next;
        ListNode* cur=head;
        ListNode* pre=NULL;


        if(left==1){
            for(int i=1; i<right; i++){
                pre=cur;
                cur=nxt;
                nxt=nxt->next;
                cur->next=pre;
            }

            head->next=nxt;

            return cur;
        }

        head->next=reverseBetween(head->next, left-1, right-1);
        return head;
    }
};





int main(){
    return 0;
}

