/*
 * 165.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
    int compareVersion(string version1, string version2) {
        vector<int> nums1=generateNums(version1);
        vector<int> nums2=generateNums(version2);
        int idx=0;
        while(idx<nums1.size()&&idx<nums2.size()){
            if(nums1[idx]>nums2[idx]){
                return 1;
            }
            if(nums1[idx]<nums2[idx]){
                return -1;
            }
            idx++;
        }
        if(idx==nums1.size()){
            while(idx<nums2.size()){
                if(nums2[idx]>0){
                    return -1;
                }
                idx++;
            }
        }
        if(idx==nums2.size()){
            while(idx<nums1.size()){
                if(nums1[idx]>0){
                    return 1;
                }
                idx++;
            }
        }

        return 0;
    }

    vector<int> generateNums(const string& version){
        vector<int> res;
        int idx=0;
        string num="";
        while(idx<version.size()){
            if(version[idx]=='.'){
                res.push_back(atoi(num.c_str()));
                num="";
                idx++;
                continue;
            }

            num=num+version[idx];
            idx++;
        }

        if(num.size()){
            res.push_back(atoi(num.c_str()));
        }

        return res;

    }
};





int main(){
    return 0;
}

