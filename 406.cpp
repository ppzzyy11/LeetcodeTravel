/*
 * 406.cpp
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> res;

        sort(people.begin(), people.end(), [](const vector<int>& nums1, const vector<int>& nums2){
                return nums1[1]==nums2[1]?nums1[0]>nums2[0]:nums1[1]<nums2[1];
                });

        for(int i=0; i<n; i++){
            int h=people[i][0];
            int k=people[i][1];

            int cnt=0;
            int idx=0;



            while(idx<res.size()&&cnt<k){
                if(res[idx][0]>=h){
                    cnt++;
                }
                idx++;
            }
            // while(idx+1<res.size()&&res[idx][1]==res[idx+1][1]){
            //     idx++;
            // }

            res.insert(res.begin()+idx, people[i] );
        }

        return res;

    }
};





int main(){
    return 0;
}

