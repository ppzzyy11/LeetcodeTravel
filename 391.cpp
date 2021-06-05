/*
 * 391.cpp
 * Copyright (C) 2021-06-05 pzy <pzy@pzy-B250M-Wind>
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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX,minY,maxX, maxY;
        minX=minY=INT_MAX;
        maxX=maxY=INT_MIN;
        unordered_map<long, int> cnt;
        int cnt1=0;
        long sum=0;
        for(int i=0; i<rectangles.size(); i++){
            int x=rectangles[i][0];
            int y=rectangles[i][1];
            int a=rectangles[i][2];
            int b=rectangles[i][3];

            sum+=(a-x)*(b-y);
            minX=min(minX, x);
            minY=min(minY, y);
            maxX=max(maxX, a);
            maxY=max(maxY, b);

            cnt[xy2idx(x, b)]++;
            cnt[xy2idx(a, y)]++;
            cnt[xy2idx(x, y)]++;
            cnt[xy2idx(a, b)]++;
        }
        cnt[xy2idx(minX, minY)]++;
        cnt[xy2idx(maxX, maxY)]++;
        cnt[xy2idx(minX, maxY)]++;
        cnt[xy2idx(maxX, minY)]++;
        for(auto it=cnt.begin(); it!=cnt.end(); it++){
            if(it->second!=2&&it->second!=4){
                return false;
            }
        }

        return sum==((maxX-minX)*(maxY-minY));
    }

    const long MOD=1000000;
    long xy2idx(int x, int y){
        return (long)x*MOD+(long)y;
    }

    pair<int, int> idx2xy(long idx){
        return {idx/MOD, idx%MOD};
    }
};





int main(){
    return 0;
}

