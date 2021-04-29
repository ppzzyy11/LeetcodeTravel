/*
 * 840.cpp
 * Copyright (C) 2021-04-27 pzy <pzy@pzy-B250M-Wind>
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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0; i+2<grid.size(); i++){
            for(int j=0; j+2<grid[0].size(); j++){
                res+=check(grid, i, j);
            }
        }
        return res;
    }

    int check(const vector<vector<int>>& grid, int x, int y){
        vector<int> cnt(9,0);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[i+x][j+y]>9||grid[i+x][j+y]==0){
                    return 0;
                }
                cnt[grid[i+x][j+y]-1]++;
                if(cnt[grid[i+x][j+y]-1]==2){
                    return false;
                }
            }
        }


        for(int i=0; i<3; i++){
            int tmp=0;
            for(int j=0; j<3; j++){
                tmp+=grid[i+x][j+y];
            }
            if(tmp!=15){
                return 0;
            }
        }
        for(int i=0; i<3; i++){
            int tmp=0;
            for(int j=0; j<3; j++){
                tmp+=grid[j+x][i+y];
            }
            if(tmp!=15){
                return 0;
            }
        }

        int tmp=0;
        for(int i=0; i<3; i++){
            tmp+=grid[x+i][y+i];
        }
        if(tmp!=15){
            return 0;
        }
        tmp=0;
        for(int i=0; i<3; i++){
            tmp+=grid[x+i][y+2-i];
        }
        if(tmp!=15){
            return 0;
        }

        return 1;
    }

};





int main(){
    return 0;
}

