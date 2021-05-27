/*
 * 200.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                res+=island(grid, i, j);
            }
        }
        return res;
    }

    bool island(vector<vector<char>>& grid, int x, int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()){
            return false;
        }

        if(grid[x][y]=='0'){
            return false;
        }

        if(grid[x][y]=='2'){
            return false;
        }

        grid[x][y]='2';
        bool rtn=true;
        x--;
        island(grid, x, y);
        x+=2;
        island(grid, x, y);
        x--;
        y--;
        island(grid, x, y);
        y+=2;
        island(grid, x, y);
        return rtn;
    }
};





int main(){
    return 0;
}

