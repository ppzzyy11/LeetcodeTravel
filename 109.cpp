/*
 * 109.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return new TreeNode(head->val);
        }
        ListNode* lh=head;
        ListNode* f=head;
        ListNode* s=head;
        while(f->next!=NULL&&f->next->next!=NULL){
            f=f->next->next;
            s=s->next;
        }

        ListNode* rh=s->next;

        ListNode* lt=lh;
        while(lt->next!=NULL&&lt->next!=s){
            lt=lt->next;
        }
        lt->next=NULL;
        s->next=NULL;


        TreeNode* node= new TreeNode(s->val);
        if(lh!=s)
            node->left=sortedListToBST(lh);
        if(rh!=s)
            node->right=sortedListToBST(rh);
        return node;
    }
};





int main(){
    return 0;
}

