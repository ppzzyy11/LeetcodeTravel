/*
 * 469.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    bool isConvex(vector<vector<int>>& points) {

        //use xiang liang ji
        int n=points.size();
        long pre,cur;
        pre=cur=0;

        for(int i=0; i<n; i++){
            int dx1=points[i][0]-points[(i-1+n)%n][0];
            int dy1=points[i][1]-points[(i-1+n)%n][1];

            int dx2=points[(i-1+n)%n][0]-points[(i-2+n)%n][0];
            int dy2=points[(i-1+n)%n][1]-points[(i-2+n)%n][1];

            cur=dx1*dy2-dx2*dy1;

            if(cur!=0){
                if(pre*cur<0){
                    return false;
                }
                pre=cur;
            }
        }
        return true;

    }
};





int main(){
    return 0;
}

