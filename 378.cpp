/*
 * 378.cpp
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> idxs(m, 0);

        while(k-->0){
            int idx=-1;
            for(int i=0; i<m; i++){
                if(idxs[i]<n){
                    if(idx==-1){
                        idx=i;
                    }else if(matrix[i][idxs[i]]<matrix[idx][idxs[idx]]){
                        idx=i;
                    }
                }else{
                    continue;
                }
            }

            if(k==0){
                return matrix[idx][idxs[idx]];
            }
            if(idx==-1){
                continue;
            }else{
                idxs[idx]++;
            }
        }

        return -1;
    }
};





int main(){
    return 0;
}

