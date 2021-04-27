/*
 * 835.cpp
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
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int res = 0;
    for(int x=0; x<img1.size(); x++){
        for(int y=0; y<img1[0].size(); y++){
            res=max(res, calculate1(img1, img2, x, y));
            res=max(res, calculate1(img1, img2, -x, y));
            res=max(res, calculate1(img1, img2, x, -y));
            res=max(res, calculate1(img1, img2, -x, -y));
        }
    }
    return res;
}

int calculate1(const vector<vector<int>>& img1, const vector<vector<int>>& img2, int x, int y){
    int res=0;
    int i=0, j=0;
    for(int i=0; i<img1.size(); i++){
        for(int j=0; j<img2.size(); j++){
            if(i+x>=0&&i<img1.size()&&i+x<img1.size()&&j+y>=0&&j<img2.size()&&j+y<img2.size()) {
                res+= (img1[i+x][j+y]&&img2[i][j]);
            }
        }
    }
    return res;
}
};





int main(){
    return 0;
}

