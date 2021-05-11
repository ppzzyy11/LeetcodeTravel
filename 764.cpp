/*
 * 764.cpp
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
    int orderOfLargestPlusSign(int n, vector<vector<int> >& mines) {
        vector<vector<int> > mat(n, vector<int>(n, 1));//-
        for(auto mine:mines){
            mat[mine[0]][mine[1]]=0;
        }
        vector<vector<int> > up=mat;
        vector<vector<int> > down=mat;
        vector<vector<int> > left=mat;
        vector<vector<int> > right=mat;
        //upward, i--;
        for(int j=0; j<n;j++){
            int cnt=0;
            for(int i=n-1; i>=0; i--){
                if(mat[i][j]==0){
                    cnt=0;
                }else{
                    cnt++;
                }
                up[i][j]=cnt;
            }
        }

        //downward, i++
        for(int j=0; j<n;j++){
            int cnt=0;
            for(int i=0; i<n; i++){
                if(mat[i][j]==0){
                    cnt=0;
                }else{
                    cnt++;
                }
                down[i][j]=cnt;
            }
        }

        //left, j--
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=n-1; j>=0; j--){
                if(mat[i][j]==0){
                    cnt=0;
                }else{
                    cnt++;
                }
                left[i][j]=cnt;
            }
        }


        //right, j++
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    cnt=0;
                }else{
                    cnt++;
                }
                right[i][j]=cnt;
            }
        }

        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res=max(res,min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])));
            }
        }

        return res;
    }

};





int main(){
    return 0;
}

