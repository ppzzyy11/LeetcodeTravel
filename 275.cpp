/*
 * 275.cpp
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
    int hIndex(vector<int>& citations) {
        int l=0, r=citations.size()-1;

        while(l+1<r){
            int m=(l+r)/2;

            if(citations[m]>=citations.size()-m){
                r=m;
            }else{
                l=m;
            }
        }
        if(citations[l]>=citations.size()-l){
            return citations.size()-l;
        }
        if(citations[r]>=citations.size()-r){
            return citations.size()-r;
        }
        return 0;
    }
};





int main(){
    return 0;
}

