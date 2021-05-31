/*
 * 435.cpp
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2){
                return interval1[1]<interval2[1];
                });

        int ans=1;
        int right=intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=right){
                right=intervals[i][1];
                ans++;
            }
        }

        return intervals.size()-ans;
    }
};




int main(){
    return 0;
}

