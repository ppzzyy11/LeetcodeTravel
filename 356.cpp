/*
 * 356.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    //y
    unordered_map<int, set<int>> y2x;
    bool isReflected(vector<vector<int>>& points) {
        for(const vector<int>& point: points){
            y2x[point[1]].insert(point[0]);
        }

        double y=INT_MAX;

        for(auto it=y2x.begin(); it!=y2x.end(); it++){
            vector<int> xes(it->second.begin(),it->second.end());
            sort(xes.begin(), xes.end());
            int s=0, e=xes.size()-1;
            while(s<=e){
                if(y==INT_MAX){
                    y=(xes[s]+xes[e])/2.0;
                }else {
                    if(y!=(xes[s]+xes[e])/2.0){
                        return false;
                    }
                }
                s++;
                e--;
            }

        }

        return true;


    }
};





int main(){
    return 0;
}

