/*
 * 581.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;

        int l=INT_MIN, r=INT_MAX;

        for(int i=0; i<nums.size(); i++){
            int k=-1;
            while(st.size()!=0&&nums[st.top()]>nums[i]){
                k=st.top();
                st.pop();
            }
            if(k!=-1){
                if(l==INT_MIN){
                    //(l,r)
                    l=st.size()==0?-1:st.top();
                }else{
                    l=min(l,st.size()==0?-1:st.top());
                }
            }
            st.push(i);
        }

        while(st.size()!=0){
            st.pop();
        }

        for(int i=nums.size()-1; i>=0; i--){
            int k=-1;
            while(st.size()!=0&&nums[st.top()]<nums[i]){
                k=st.top();
                st.pop();
            }
            if(k!=-1){
                if(r==INT_MAX){
                    r=st.size()==0?nums.size():st.top();
                }else{
                    r=max(r,st.size()==0?(int)nums.size():st.top());
                }
            }
            st.push(i);
        }

        return l==INT_MIN?0:r-l-1;
    }
};


class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp=nums;
        sort(nums.begin(), nums.end());
        int l=-1, r=-1;
        for(int i=0; i<nums.size(); i++){
            if(tmp[i]!=nums[i]){
                if(l==-1){
                    l=r=i;
                }else{
                    r=max(r, i);
                }
            }
        }

        return r==-1?0:r-l+1;

    }
};





int main(){
    return 0;
}

