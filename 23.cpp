/*
 * 23.cpp
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size()-1);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL||l2==NULL){
            return l1?l1:l2;
        }

        ListNode* dummy=new ListNode();
        ListNode* node=dummy;
        while(l1||l2){
            if(l1&&l2){
                if(l1->val<l2->val){
                    node->next=l1;
                    l1=l1->next;
                }else{
                    node->next=l2;
                    l2=l2->next;
                }
            }else if(l1){
                node->next=l1;
                l1=l1->next;
            }else if(l2){
                node->next=l2;
                l2=l2->next;
            }else{
                ;
            }
            node=node->next;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int s, int e){
        if(s>e){
            return NULL;
        }
        if(s==e){
            return lists[s];
        }
        if(s+1==e){
            return mergeTwoLists(lists[s], lists[e]);
        }

        int m=(s+e)/2;
        ListNode* l = mergeKLists(lists, s, m);
        ListNode* r = mergeKLists(lists, m+1, e);
        return mergeTwoLists(l, r);
    }

};





int main(){
    return 0;
}

