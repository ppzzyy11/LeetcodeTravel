/*
 * 311.cpp
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
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {

        int m1=mat1.size();
        int n1=mat1[0].size();

        int m2=mat2.size();
        int n2=mat2[0].size();

        //n1==m2
        vector<vector<int>> res(m1, vector<int>(n2, 0));

        for(int i=0; i<m1; i++){
            for(int j=0; j<n2; j++){
                for(int k=0; k<n1; k++){
                    res[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

