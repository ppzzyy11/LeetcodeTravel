/*
 * 935.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
    const int MOD=1000000007;
    vector<vector<int>> nxts{
        {4,6},//0
            {6,8},
            {7,9},//2
            {4,8},
            {3,9,0},//4
            {},
            {1,7,0},//6
            {2,6},
            {1,3},//8
            {2,4}
    };
public:
    int knightDialer(int n) {
        vector<vector<int> > dp(n, vector<int>(10, 0));
        //i==0, n==1
        for(int j=0; j<=9; j++){
            dp[0][j]=1;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=9; j++){
                for(const auto& nxt: nxts[j]){
                    dp[i][j]+=dp[i-1][nxt];
                    dp[i][j]=dp[i][j]%MOD;
                }
            }
        }

        int sum=0;
        for(int j=0; j<=9; j++){
            sum+=dp[n-1][j];
            sum=sum%MOD;
        }
        return sum;
    }
};



class SolutionTLE {
    const int MOD=1000000007;
    vector<vector<int>> nxt{
        {4,6},//0
            {6,8},
            {7,9},//2
            {4,8},
            {3,9,0},//4
            {},
            {1,7,0},//6
            {2,6},
            {1,3},//8
            {2,4}
    };
    //n num
    unordered_map<int, unordered_map<int, int> > rec;
public:
    int knightDialer(int n) {
        if(n==1){
            return 10;
        }
        int sum=0;
        for(int i=0; i<=9; i++){
            sum+=getCom(n-1, i);
            sum=sum%MOD;
        }
        return sum;
    }

    int getCom(int n, int num){
        if(rec.count(n)!=0&&rec[n].count(num)!=0){
            return rec[n][num];
        }
        if(n==1){
            return rec[n][num]=nxt[num].size();
        }

        int res=0;
        for(int i=0; i<nxt[num].size(); i++){
            res+=getCom(n-1, nxt[num][i]);
            res=res%MOD;
        }
        return rec[n][num]=res%MOD;

    }
};





int main(){
    return 0;
}

