/*
 * 750.cpp
 * Copyright (C) 2021-05-11 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int countCornerRectangles(vector<vector<int> >& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1||n==1){
            return 0;
        }
        int res=0;
        for(int i=0; i<m ;i++){
            for(int j=0; j<i; j++){
                int cnt=0;
                for(int k=0; k<n; k++){
                    if(grid[i][k]==1&&grid[j][k]==1){
                        cnt++;
                    }
                }
                res+=(cnt-1)*cnt/2;
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

