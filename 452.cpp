/*
 * 452.cpp
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
    int findMinArrowShots(vector<vector<int>>& points) {
        //
        if(points.size()==0){
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& point1, const vector<int>& point2){
                return point1[1]<point2[1];
                });

        int ans=1;
        int p=points[0][1];

        for(const vector<int>& point: points){
            if(point[0]>p){
                p=point[1];
                ans++;
            }
        }

        return ans;
    }
};





int main(){
    return 0;
}

