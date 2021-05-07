/*
 * 363.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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

// need be summmarised for binary search in unsorted array

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> prefixSumByCol(m+1, vector<int>(n, 0));

        //prefix sum by column
        for(int j=0; j<n; j++){
            int sum=0;
            for(int i=0; i<m; i++){
                sum+=matrix[i][j];
                prefixSumByCol[i+1][j]=sum;
            }
        }

        int res=INT_MIN;
        for(int i0=0; i0<m; i0++){
            for(int i1=i0; i1<m; i1++){
                //sliding window not working here
                set<int> rec;
                int sum=0;
                for(int j=0; j<n; j++){
                    sum+=prefixSumByCol[i1+1][j]-prefixSumByCol[i0][j];


                    //binary search in unordered_set
                    auto lb = rec.lower_bound(sum-k);
                    if(lb!=rec.end()){
                        res=max(res, sum-*lb);
                    }
                    rec.insert(sum);
                }
            }
        }
        return res;


    }
};





int main(){
    return 0;
}

