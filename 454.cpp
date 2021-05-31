/*
 * 454.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> cnt1;
        unordered_map<int, int> cnt2;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                cnt1[nums1[i]+nums2[j]]++;
            }
        }

        for(int i=0; i<nums3.size(); i++){
            for(int j=0; j<nums4.size(); j++){
                cnt2[nums3[i]+nums4[j]]++;
            }
        }

        int res=0;
        for(auto it=cnt1.begin(); it!=cnt1.end(); it++){
            res+=it->second*cnt2[0-it->first];
        }

        return res;
    }
};





int main(){
    return 0;
}

