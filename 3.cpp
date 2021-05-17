/*
 * 3.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        vector<int> cnt(256,0);
        int res=0;
        while(r<s.size()){
            cnt[s[r]]++;

            //[l,r]
            while(l<=r&&cnt[s[r]]>1){
                cnt[s[l++]]--;
            }
            //[l,r]
            res=max(res, r-l+1);
            r++;
        }

        return res;
    }
};





int main(){
    return 0;
}

