/*
 * 240.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int up=0;
        int left=0;
        int down=matrix.size()-1;
        int right=matrix[0].size()-1;

        //from left to right in the [up] row
        for(int i=0; i<m; i++){
            int l=left, r=right;
            while(l+1<r){
                int m=(l+r)/2;
                if(matrix[i][m]==target){
                    return true;
                }else if(matrix[i][m]>target){
                    r=m;
                }else{
                    l=m;
                }
            }

            if(matrix[i][l]==target||matrix[i][r]==target){
                return true;
            }
        }


        //from up to bottom
        for(int j=0; j<n; j++){
            int l=up, r=down;
            while(l+1<r){
                int m=(l+r)/2;
                if(matrix[m][j]==target){
                    return true;
                }else if(matrix[m][j]>target){
                    r=m;
                }else{
                    l=m;
                }
            }

            if(matrix[l][j]==target||matrix[r][j]==target){
                return true;
            }
        }

        return false;

    }


};





int main(){
    return 0;
}

