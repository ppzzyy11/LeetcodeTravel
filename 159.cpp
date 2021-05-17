/*
 * 159.cpp
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l=0, r=0;
        vector<int> cnt(256, 0);
        int num=0;
        int res=0;
        while(r<s.size()){
            cnt[s[r]]++;
            if(cnt[s[r]]==1){
                num++;
            }
            if(num<=2){
                res=max(res, r-l+1);
            }
            while(num>2){
                cnt[s[l]]--;
                if(cnt[s[l]]==0){
                    num--;
                }
                l++;
            }
            r++;
        }
        return res;
    }
};





int main(){
    return 0;
}

