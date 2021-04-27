/*
 * 695.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //0 for water, 1 for island, -1 for visited
        int res=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                res=max(res, visit(grid, i, j));
            }
        }
        return res;
    }

    int visit(vector<vector<int>>& grid, int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()||grid[i][j]==0||grid[i][j]==-1){
            return 0;
        }
        grid[i][j]=-1;
        return 1
            +visit(grid,i-1, j)
            +visit(grid,i+1, j)
            +visit(grid,i, j-1)
            +visit(grid,i, j+1);
    }
};





int main(){
    return 0;
}

