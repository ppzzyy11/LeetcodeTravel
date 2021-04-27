/*
 * 562.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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
    int longestLine(vector<vector<int>>& M) {

        int res=0;
        if(M.size()==0){
            return res;
        }
        for(int i=0; i<M.size() ;i++){
            res=max(res, getLongst(M, i, 0, 1));
            res=max(res, getLongst(M, i, 0, 2));
            res=max(res, getLongst(M, i, 0, 3));
        }

        for(int j=0; j<M[0].size(); j++){
            res=max(res, getLongst(M, 0, j, 0));
            res=max(res, getLongst(M, 0, j, 2));
            res=max(res, getLongst(M, M.size()-1, j, 3));
        }

        return res;

    }

    int getLongst(const vector<vector<int>>& mat, int i, int j, int direction){
        if(i<0||j<0||i>=mat.size()||j>=mat[i].size()){
            return 0;
        }
        int res =0;
        int tmp=0;
        while(i>=0&&j>=0&&i<mat.size()&&j<mat[i].size()){
            if(mat[i][j]==1){
                tmp++;
                res=max(res, tmp);
            }else{
                tmp=0;
            }


            switch(direction){
                //i++
                case 0:
                    i++;
                    break;

                //j++
                case 1:
                    j++;
                    break;

                //i++, j++
                case 2:
                    i++;
                    j++;
                    break;

                //i--, j++
                case 3:
                    i--;
                    j++;
                    break;
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

