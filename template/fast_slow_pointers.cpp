/*
 * 457.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 * */


#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//for nums
class Solution {
public:

    bool detecCircle(vector<int>& nums, int idx){
        vector<int> path;
        //fast, slow pointers
        int fast=idx, slow=idx;
        bool cicular=false;
        //detect cycle
        while(nums[fast]!=0&&nums[nxtIdx(nums, fast)]){
            path.push_back(slow);
            fast=nxtIdx(nums, nxtIdx(nums, fast));
            slow=nxtIdx(nums, slow);
            if(fast==slow){
                cicular=true;
                break;
            }
        }

        vector<int> cycle;
        if(cicular==false){
            set0Path(nums, path);
            return false;
        }else{
            //fast=idx;
            //while(fast!=slow){
                //fast=nxtIdx(nums, fast);
                //slow=nxtIdx(nums, slow);
            //}
            //slow is the start of cycle
            cycle=getCycle(nums, slow);
            bool res = legal(nums, cycle);
            set0Path(nums, path);
            set0Path(nums, cycle);
            return res;
        }


    }

    int nxtIdx(const vector<int>& nums, int idx){
        idx=(idx+nums.size())%nums.size();
        return (idx+nums[idx]+nums.size())%nums.size();

    }


    void set0Path(vector<int>& nums, const vector<int>& idxs){
        for(auto idx: idxs){
            nums[idx]=0;
        }
    }

    vector<int> getCycle(const vector<int>& nums, int start){
        vector<int> cycle;
        int idx=start;
        do{
            cycle.push_back(idx);
            idx=nxtIdx(nums, idx);
        }while(idx!=start);
        return cycle;
    }
};





int main(){
    vector<int> nums{2,-1,1,2,2};
    return 0;
}


//for linked list
public class SolutionLinkedList {
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return null;

        // 找出相遇点
        ListNode slow = head;       // 慢指针，每次走一步
        ListNode fast = head;       // 快指针，每次走两步
        boolean isCycle = false;    // 是否有环标志

        while (fast != null && fast.next != null){
            fast = fast.next.next;   // 走两步
            slow = slow.next;        // 走一步
            if (fast == slow){
                isCycle = true;     // 有环标志
                break;              // 退出循环
            }
        }

        // 有环则找出起始点
        if (isCycle){
            ListNode first = head;      // 从头结点开始遍历，最终和慢指针在环入口点相遇
            while (first != slow){
                first = first.next;
                slow = slow.next;
            }
            return slow;
        }else {
            return null;
        }
    }
}

————————————————
版权声明：本文为CSDN博主「稻草人0.0」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_43989102/article/details/111304495
