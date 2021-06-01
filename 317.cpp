/*
 * 317.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    vector<pair<int, int>> dirs{
        {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, INT_MAX));

        int cnt1=0;
        int cnt0=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    cnt1++;
                }else if(grid[i][j]==0){
                    cnt0++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));

                    //BFS and upgrade sum matrix
                    queue<pair<int, int>> que;
                    que.push({i,j});

                    visited[i][j]=true;

                    int tmp_cnt1=1;
                    int tmp_cnt0=0;

                    int step=0;
                    while(que.size()){
                        int size=que.size();
                        step++;

                        while(size-->0){
                            pair<int, int> fnt=que.front();
                            que.pop();

                            int ix=fnt.first;
                            int iy=fnt.second;

                            for(const pair<int, int>& dir: dirs){
                                int dx=dir.first;
                                int dy=dir.second;

                                int x=ix+dx;
                                int y=iy+dy;
                                if(x>=0&&x<m&&y>=0&&y<n){
                                    if(visited[x][y]==false){
                                        visited[x][y]=true;
                                        if(grid[x][y]==1){
                                            tmp_cnt1++;
                                        }
                                        if(grid[x][y]==0){
                                            tmp_cnt0++;
                                            if(sum[x][y]==INT_MIN){
                                                continue;
                                            }
                                            if(sum[x][y]==INT_MAX){
                                                sum[x][y]=0;
                                            }
                                            sum[x][y]+=step;
                                            que.push({x,y});
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if(tmp_cnt1!=cnt1){
                        return -1;
                    }
                    if(tmp_cnt0!=cnt0){
                        for(int i=0; i<m; i++){
                            for(int j=0; j<n; j++){
                                if(visited[i][j]==false){
                                    sum[i][j]=INT_MIN;
                                }
                            }
                        }
                    }
                }
            }
        }

        int res=INT_MAX;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0&&sum[i][j]!=INT_MIN){
                    res=min(res, sum[i][j]);
                }
            }
        }

        return res==INT_MAX?-1:res;

    }
};





int main(){
    return 0;
}

