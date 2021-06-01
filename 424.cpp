/*
 * 424.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);

        int res=0;
        int l=0, r=0;
        while(r<s.size()){
            //[l,r]
            cnt[s[r]-'A']++;

            while(!possible(cnt, l, r, k)){
                cnt[s[l++]-'A']--;
            }

            res=max(res, r-l+1);
            r++;
        }

        return res;
    }

    bool possible(const vector<int>& cnt,int l, int r, int k){
        int maxCnt=0;
        for(const int c: cnt){
            maxCnt=max(maxCnt, c);
        }

        int diff=r-l+1-maxCnt;
        return diff<=k;
    }
};





int main(){
    return 0;
}

