/*
 * 352.cpp
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

using namespace std;




class SummaryRanges {
    vector<vector<int>> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        vector<int> interval(2, val);

        //find index to insert, try to merge other intervals

        //no need to insert
        int i;
        for(i=0; i<intervals.size(); i++){
            if(intervals[i][0]<=val&&intervals[i][1]>=val){
                return ;
            }else if(intervals[i][0]>val){
                //insert before i
                break;
            }
        }

        //previous to merge
        int p=i-1;
        //next to merge
        int n=i;

        bool mergeP=false;
        bool mergeN=false;
        if(p>=0&&intervals[p][1]==val-1){
            mergeP=true;
        }
        if(n<intervals.size()&&intervals[n][0]==val+1){
            mergeN=true;
        }

        if(mergeP&&mergeN){
            vector<int> interval(2, 0);
            interval[0]=intervals[p][0];
            interval[1]=intervals[n][1];
            intervals.erase(intervals.begin()+p, intervals.begin()+n+1);
            intervals.insert(intervals.begin()+p, interval);
        }else if(mergeP){
            intervals[p][1]++;
        }else if(mergeN){
            intervals[n][0]--;
        }else {
            vector<int> interval(2, val);
            intervals.insert(intervals.begin()+n, interval);
        }

    }

    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */





int main(){
    return 0;
}

