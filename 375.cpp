/*
 * 375.cpp
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



class Solution {
public:
    int getMoneyAmount(int n) {
        //minimal money to make sure win game
        vector<vector<int>> mem(n+1, vector<int>(n+1, INT_MAX));
        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                if(j==i){
                    mem[i][j]=0;
                }else if(j==i+1){
                    mem[i][j]=i;
                }else{
                    for(int k=i+1; k<j; k++){
                        //guess K
                        mem[i][j]=min(mem[i][j], max(mem[i][k-1],mem[k+1][j])+k);
                    }
                }
            }
        }

        return mem[1][n];
    }
};





int main(){
    return 0;
}

