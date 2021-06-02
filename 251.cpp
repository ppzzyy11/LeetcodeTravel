/*
 * 251.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



class Vector2D {
    int x,y;
    vector<vector<int>> mat;
public:
    Vector2D(vector<vector<int>>& vec) {
        mat=vec;
        x=0,y=0;
    }

    int next() {
        int val=mat[x][y];
        y++;
        while(x<mat.size()&&y==mat[x].size()){
            x++;
            y=0;
        }
        return val;
    }

    bool hasNext() {
        while(x<mat.size()&&y==mat[x].size()){
            x++;
            y=0;
        }
        return x<mat.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */





int main(){
    return 0;
}

