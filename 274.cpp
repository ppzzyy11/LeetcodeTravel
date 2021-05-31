/*
 * 274.cpp
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
        if(citations.size()==0){
            return 0;
        }
        sort(citations.begin(), citations.end());

        int l=0, r=citations.back();
        while(l+1<r){
            int m=(l+r)/2;

            if(possible(citations, m)){
                l=m;
            }else{
                r=m;
            }
        }
        if(possible(citations, r)){
            return r;
        }
        return l;

    }

    bool possible(const vector<int>& citations, int h){
        int cnt=0;
        for(int i=0; i<citations.size(); i++){
            if(citations[i]>=h){
                cnt++;
            }
        }
        return cnt>=h;

    }
};





int main(){
    return 0;
}

