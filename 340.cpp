/*
 * 340.cpp
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l=0, r=0;
        int cnt=0;
        int res=0;
        vector<int> rec(256,0);
        while(r<s.size()){
            rec[s[r]]++;

            if(rec[s[r]]==1){
                cnt++;
            }
            while(cnt>k){
                rec[s[l]]--;

                if(rec[s[l]]==0){
                    cnt--;
                }
                l++;
            }

            res=max(res, r-l+1);

            r++;
        }
        return res;
    }
};





int main(){
    return 0;
}

