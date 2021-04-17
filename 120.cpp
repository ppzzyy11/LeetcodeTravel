/*
 * 120.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
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

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pre;
        vector<int> cur;
        for(int i=0; i<triangle.size(); i++){
            pre=cur;
            cur.resize(i+1, INT_MAX);
            for(int j=0; j<triangle[i].size(); j++){
                if(i==0){
                    cur[j]=triangle[i][j];
                }else{
                    if(j==0){
                        cur[j]=pre[j]+triangle[i][j];
                    }else if(j==triangle[i].size()-1){
                        cur[j]=pre[j-1]+triangle[i][j];
                    }else{
                        cur[j]=min(pre[j],pre[j-1])+triangle[i][j];
                    }
                }

            }
        }
        int res = INT_MAX;
        for(auto sum: cur){
            res=min(res, sum);
        }
        return res;

    }
};





int main(){
    return 0;
}

