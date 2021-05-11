/*
 * 799.cpp
 * Copyright (C) 2021-05-11 pzy <pzy@pzy-B250M-Wind>
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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> pre(100, 0);
        vector<double> cur(100, 0);
        cur[0]=poured;
        while(query_row-->0){
            int n=query_row+1;
            pre=cur;
            for(int i=0; i<cur.size(); i++){
                cur[i]=0;
            }
            for(int i=0; i<pre.size()-1; i++){
                if(pre[i]>1.0){
                    cur[i]+=(pre[i]-1.0)/2.0;
                    cur[i+1]+=(pre[i]-1.0)/2.0;
                }
            }

        }
        return cur[query_glass]>1.0?1.0:cur[query_glass];
    }
};





int main(){
    return 0;
}

