/*
 * 361.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        vector<vector<int>> kill(grid.size(), vector<int>(grid[0].size(), 0));
        int m=grid.size();
        int n=grid[0].size();
        int pre=0;
        for(int i=0; i<m; i++){
            //from left to right
            pre=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]=='E'){
                    pre++;
                }else if(grid[i][j]=='W'){
                    pre=0;
                }else{//gird[i][j]=='0'
                    kill[i][j]+=pre;
                }
            }

            //from right to left
            pre=0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]=='E'){
                    pre++;
                }else if(grid[i][j]=='W'){
                    pre=0;
                }else{//gird[i][j]=='0'
                    kill[i][j]+=pre;
                }
            }
        }


        for(int j=0; j<n; j++){
            //from top to bottom
            pre=0;
            for(int i=0; i<m; i++){
                if(grid[i][j]=='E'){
                    pre++;
                }else if(grid[i][j]=='W'){
                    pre=0;
                }else{//gird[i][j]=='0'
                    kill[i][j]+=pre;
                }
            }

            //from bottom to top
            pre=0;
            for(int i=m-1; i>=0; i--){
                if(grid[i][j]=='E'){
                    pre++;
                }else if(grid[i][j]=='W'){
                    pre=0;
                }else{//gird[i][j]=='0'
                    kill[i][j]+=pre;
                }
            }
        }

        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res=max(res, kill[i][j]);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

