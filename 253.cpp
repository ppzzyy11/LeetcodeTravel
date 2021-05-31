/*
 * 253.cpp
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

class cmp{
    public:
        bool operator()(const vector<int>& interval1, vector<int>& interval2){
            return interval1[1]>interval2[1];
        }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2){
                return interval1[0]==interval2[0]?(interval1[1]<interval2[1]):(interval1[0]<interval2[0]);
                });

        priority_queue<vector<int>, vector<vector<int>>,cmp> pque;

        int n=intervals.size();
        int s=0;
        int e=s;
        int ans=0;
        for(int i=0; i<n; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            while(pque.size()!=0&&pque.top()[1]<=s){
                pque.pop();
            }
            pque.push(intervals[i]);

            ans=max(ans, (int)pque.size());
        }

        return ans;


    }
};





int main(){
    return 0;
}

