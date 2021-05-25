/*
 * 233.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    int countDigitOne(int n) {
        int i=0;
        int num=n;
        while(n>0){
            i++;
            n=n/10;
        }
        vector<vector<long>> cnt1(i+1, vector<long>(i+1, 0));
        //10^(i-1), 10^i-1 ge 1
        cnt1[0][0]=1;
        if(num!=0)
        {
            cnt1[1][0]=8;
            cnt1[1][1]=1;
        }

        for(int i=2; i<cnt1.size(); i++){
            for(int j=0; j<cnt1[i].size(); j++){
                cnt1[i][j]+=cnt1[i-1][j]*9;
                if(j!=0){
                    cnt1[i][j]+=cnt1[i-1][j-1];
                }
            }
        }


        int res=0;
        vector<int> digits=num2digits(num);
        //cnt1 biao zhun bufen

        //extra bu fen

        return recur(digits, 0, 0, cnt1);

    }

    vector<int> num2digits(int num){
        vector<int> res;
        while(num>0){
            res.push_back(num%10);
            num=num/10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int recur(const vector<int>& digits, int idx, int add, const vector<vector<long>>& cnt1){
        if(idx>=digits.size()){
            return add;
        }
        int res=0;
        for(int i=0; i<=digits[idx]; i++){
            if(i==digits[idx]){
                res+=recur(digits, idx+1, add+(i==1), cnt1);
            }else {
                if(i==1)
                    add++;
                if(idx==digits.size()-1){
                    res+=add;
                }else{
                    res+=getSum(cnt1, digits.size()-idx, add);
                }
                if(i==1)
                    add--;
            }
        }

        return res;
    }
    int getSum(const vector<vector<long>>& cnt1, int x, int add){

        int res=0;
        for(int i=0; i<x; i++){
            for(int j=0; j<cnt1[i].size(); j++){
                // if(cnt1[i][j]*j!=0)
                {
                res+=cnt1[i][j]*j+add*cnt1[i][j];
                }
            }
        }

        return res;
    }

};





int main(){
    return 0;
}

