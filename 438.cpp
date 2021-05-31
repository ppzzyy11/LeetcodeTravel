/*
 * 438.cpp
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
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()){
            return {};
        }
        vector<int> cnt(26, 0);
        for(char ch: p){
            cnt[ch-'a']++;
        }

        vector<int> res;
        int l=0, r=0;
        int cnt_cnt=0;
        vector<int> tmp_cnt(26, 0);
        while(r<p.size()){
            tmp_cnt[s[r]-'a']++;
            if(tmp_cnt[s[r]-'a']<=cnt[s[r]-'a']){
                cnt_cnt++;
            }
            r++;
        }

        if(cnt_cnt==p.size()){
            res.push_back(l);
        }

        //[l, r)
        while(r<s.size()){
            tmp_cnt[s[r]-'a']++;
            if(tmp_cnt[s[r]-'a']<=cnt[s[r]-'a']){
                cnt_cnt++;
            }
            r++;


            tmp_cnt[s[l]-'a']--;
            if(tmp_cnt[s[l]-'a']<cnt[s[l]-'a']){
                cnt_cnt--;
            }
            l++;

            if(cnt_cnt==p.size()){
                res.push_back(l);
            }
        }

        return res;
    }
};





int main(){
    return 0;
}

