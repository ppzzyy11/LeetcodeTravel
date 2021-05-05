/*
 * get_max_sequence.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;
/**
 * get sequence of length k from nums
 */
vector<int> getMaxSeq(const vector<int>& nums, int k){
        vector<int> stack(k,0);
        int len=nums.size();
        int top=-1;
        int remain=len-k;
        for(int i=0; i<len; i++){
            int num=nums[i];
            while(top>=0&&stack[top]<num&&remain>0){
                top--;
                remain--;
            }
            if(top<k-1){
                stack[++top]=num;
            }else{
                remain--;
            }
        }
        while(stack.size()>len){
            stack.pop_back();
        }

        return stack;
    }





int main(){
    return 0;
}

