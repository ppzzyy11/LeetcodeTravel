/*
 * 950.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        return helper(deck, 0, deck.size()-1);
    }

    vector<int> helper(const vector<int>& nums, int s, int e){
        vector<int> res;
        if(s>e||e>=nums.size()||s<0){
            return res;
        }
        int m=(s+e)/2;
        return merge(split(nums, s, m), helper(nums, m+1, e));
    }

    vector<int> split(const vector<int>& nums, int s, int e){
        vector<int> res;
        for(int i=s; i<=e; i++){
            res.push_back(nums[i]);
        }
        return res;
    }

    vector<int> merge(const vector<int>& nums1, vector<int> nums2){
        vector<int> res;
        int i=0, j=0;
        if(nums1.size()>nums2.size()&&nums2.size()!=0){
            int back=nums2.back();
            nums2.pop_back();
            reverse(nums2.begin(), nums2.end());
            nums2.push_back(back);
            reverse(nums2.begin(), nums2.end());
        }
        while(i<nums1.size()||j<nums2.size()){
            if(i<nums1.size()){
                res.push_back(nums1[i++]);
            }

            if(j<nums2.size()){
                res.push_back(nums2[j++]);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

