/*
 * 395.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    int longestSubstring(string s, int k) {
        if(s.size()==0){
            return 0;
        }
        vector<int> cnt(26, 0);
        for(int i=0; i<s.size(); i++){
            cnt[s[i]-'a']++;
        }
        vector<int> idxs;
        for(int i=0; i<s.size(); i++){
            if(cnt[s[i]-'a']<k){
                idxs.push_back(i);
            }
        }

        if(idxs.size()==0){
            return s.size();
        }
        idxs.push_back(s.size());
        int res=0;

        for(int i=0; i<idxs.size(); i++){
            if(i==0){
                res=max(res, longestSubstring(s.substr(0, idxs[i]), k) );
            }else{
                if(idxs[i-1]+1!=idxs[i])
                res=max(res, longestSubstring(s.substr(idxs[i-1]+1, idxs[i]-idxs[i-1]-1), k) );
            }
        }

        return res;
    }
};





int main(){
    return 0;
}

