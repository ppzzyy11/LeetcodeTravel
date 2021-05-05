/*
 * 321.cpp
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

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        for(int k1=0; k1<=k; k1++ ){
            int k2=k-k1;
            vector<int> seq1=getMaxSeq(nums1, k1);
            vector<int> seq2=getMaxSeq(nums2, k2);
            vector<int> tmp=merge(seq1, seq2);
            if(compare(tmp, res)>0){
                res=tmp;
            }
        }
        return res;

    }

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

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2){
        vector<int> res;
        int idx1=0, idx2=0;
        while(idx1<nums1.size()||idx2<nums2.size()){
            if(compare(nums1, idx1, nums2, idx2)>0){
                res.push_back(nums1[idx1++]);
            }else{
                res.push_back(nums2[idx2++]);
            }
        }
        return res;
    }

    //+ nums1>nums2
    //0 nums1=nums2
    //- nums1<nums2
    int compare(vector<int>& nums1, vector<int>& nums2){
        deletePrefix0(nums1);
        deletePrefix0(nums2);
        if(nums1.size()!=nums2.size()){
            return nums1.size()>nums2.size()?1:-1;
        }
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]!=nums2[i]){
                return nums1[i]>nums2[i]?1:-1;
            }
        }
        return 0;
    }

    int compare(const vector<int>& nums1, int idx1, const vector<int>& nums2, int idx2){
        if(idx1>=nums1.size()){
            return -1;
        }
        if(idx2>=nums2.size()){
            return 1;
        }
        for(int i=0; i+idx1<nums1.size()&&i+idx2<nums2.size(); i++){
            if(nums1[i+idx1]!=nums2[i+idx2]){
                return nums1[i+idx1]>nums2[i+idx2]?1:-1;
            }
        }
        if(nums1.size()-idx1-1!=nums2.size()-idx2-1){
            return nums1.size()-idx1-1>nums2.size()-idx2-1?1:-1;
        }
        return 0;
    }

    void deletePrefix0(vector<int>& nums){
        reverse(nums.begin(), nums.end());
        while(nums.size()!=0&&nums.back()==0){
            nums.pop_back();
        }
        reverse(nums.begin(), nums.end());
    }
};





int main(){
    return 0;
}

