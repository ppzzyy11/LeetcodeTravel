/*
 * 490.cpp
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
    vector<vector<int>> rec;
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        int n=maze[0].size();
        rec.resize(m, vector<int>(n, -1));
        int res= dfs(maze, start[0], start[1], destination);
        return res==1;

    }

    int dfs(const vector<vector<int>>& maze, int x, int y, const vector<int>& des){
        if(x<0||y<0||x>=maze.size()||y>=maze[0].size()||maze[x][y]==1){
            return false;
        }
        //search in memorization
        if(rec[x][y]!=-1){
            return rec[x][y];
        }
        if(x==des[0]&&y==des[1]){
            return rec[x][y]=1;
        }

        //mark being dfsed
        rec[x][y]=-2;

        //4 directions
        vector<vector<int>> directions={
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        for(int i=0; i<directions.size(); i++){
            int dx=directions[i][0];
            int dy=directions[i][1];
            vector<int> d=go(maze,x, y, dx, dy);
            if(d[0]!=x||d[1]!=y){
                if(dfs(maze, d[0], d[1], des)==1){
                    return rec[x][y]=1;
                }
            }

        }

        //memorize and return
        return rec[x][y]=0;
    }


    vector<int> go(const vector<vector<int>>& maze, int x, int y, int dx, int dy){
        while(x+dx>=0&&x+dx<maze.size()&&y+dy>=0&&y+dy<maze[0].size()&&maze[x+dx][y+dy]!=1){
            x+=dx;
            y+=dy;
        }
        vector<int> res;
        res.push_back(x);
        res.push_back(y);

        return res;
    }


};





int main(){
    return 0;
}

