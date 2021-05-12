/*
 * 838.cpp
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
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> l(n, INT_MAX);
        vector<int> r(n, INT_MAX);
        int len=INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i]=='L'){
                len=0;
            }else if(dominoes[i]=='R'){
                len=INT_MAX;
            }else{
                if(len!=INT_MAX)
                     len++;
            }
            l[i]=len;
        }

        len=INT_MAX;
        for(int i=0; i<n; i++){
            if(dominoes[i]=='R'){
                len=0;
            }else if(dominoes[i]=='L'){
                len=INT_MAX;
            }else{
                    if(len!=INT_MAX)
                     len++;
            }
            r[i]=len;
        }

        for(int i=0; i<n; i++){
            if(l[i]==r[i]){
                dominoes[i]='.';
            }else if(l[i]>r[i]){
                dominoes[i]='R';
            }else{
                dominoes[i]='L';
            }
        }
        return dominoes;
    }
};





int main(){
    return 0;
}

