/*
 * 296.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xs;
        vector<int> ys;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int dx=xs[xs.size()/2];
        int dy=ys[ys.size()/2];

        int sum=0;
        for(int x: xs){
            sum+=abs(dx-x);
        }
        for(int y: ys){
            sum+=abs(dy-y);
        }

        return sum;
    }
};





int main(){
    return 0;
}

