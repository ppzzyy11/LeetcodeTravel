/*
 * 531.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        //'B', 'W'
        int res=0;
        for(int i=0; i<picture.size(); i++){
            for(int j=0; j<picture[i].size(); j++){
                if(picture[i][j]=='B'){
                    if(isLoney(picture, i, j)){
                        res++;
                        findWithChar(picture, i, j, 'E');
                    }
                }
            }
        }
        return res;
    }

    bool isLoney(const vector<vector<char>>& mat, int i, int j){
        if(i<0||j<0||i>=mat.size()||j>=mat[i].size()){
            return false;
        }

        for(int x=0; x<mat.size(); x++){
            if(i==x){
                continue;
            }
            if(mat[x][j]=='B'){
                return false;
            }
        }

        for(int y=0; y<mat[i].size(); y++){
            if(j==y){
                continue;
            }
            if(mat[i][y]=='B'){
                return false;
            }
        }

        return true;
    }


    bool findWithChar(vector<vector<char>>& mat, int i, int j, char ch){
        if(i<0||j<0||i>=mat.size()||j>=mat[i].size()){
            return false;
        }

        for(int x=0; x<mat.size(); x++){
            mat[x][j]=ch;
        }

        for(int y=0; y<mat[i].size(); y++){
            mat[i][y]=ch;
        }
        return true;
    }
};





int main(){
    return 0;
}

