/*
 * 60.cpp
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
    string getPermutation(int n, int k) {
        string str;
        for(int i=0; i<n; i++){
            str=str+(char)(i+'1');
        }
        //first find (r!)th
        int r=1;
        int ith=1;
        while(ith*(r+1)<=k){
            ith*=r+1;
            r++;
        }

        reverse(str.end()-r, str.end());
        k-=ith;

        while(k--){
            str=nextpermutation(str);
        }

        return str;
    }

    string nextpermutation(string str){
        int i=0;
        for(i=str.size()-2;i>=0;i--){
            if(str[i]<str[i+1])
                break;
        }

        if(i==-1){
            reverse(str.begin(), str.end());
        }else{
            for(int j=str.size()-1; j>=i+1; j--){
                if(str[i]<str[j]){
                    swap(str[i], str[j]);
                    reverse(str.begin()+i+1, str.end());
                    break;
                }
            }
        }

        return str;

    }
};





int main(){
    return 0;
}

