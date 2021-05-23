/*
 * 223.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res=(ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        if(ax1>=bx2||ay1>=by2||ax2<=bx1||ay2<=by1){
            ;
        }else{
            int up=min(ay2, by2);
            int down=max(ay1, by1);
            int left=max(ax1, bx1);
            int right=min(ax2, bx2);
            res-=(up-down)*(right-left);
        }
        return res;
    }
};





int main(){
    return 0;
}

