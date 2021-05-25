/*
 * 447.cpp
 * Copyright (C) 2021-05-24 pzy <pzy@pzy-B250M-Wind>
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0; i<points.size(); i++){
            unordered_map<int, int> cnt;
            for(int j=0; j<points.size(); j++){
                if(j==i){
                    continue;
                }
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                int dst=dx*dx+dy*dy;
                cnt[dst]++;
            }

            for(auto it=cnt.begin(); it!=cnt.end(); it++){
                int time=it->second;
                res+=time*(time-1);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

