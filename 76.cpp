/*
 * 76.cpp
 * Copyright (C) 2021-05-18 pzy <pzy@pzy-B250M-Wind>
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
    string minWindow(string s, string t) {
        vector<int> cnt2refer(256, 0);
        for(char ch:t){
            cnt2refer[ch]++;
        }

        string res="";
        vector<int> cnt(256,0);
        int num=0;
        int l=0, r=0;
        while(r<s.size()){
            cnt[s[r]]++;
            if(cnt[s[r]]<=cnt2refer[s[r]]){
                num++;
            }
            //[l,r]
            while(num==t.size()){
                if(res==""){
                    res=s.substr(l, r-l+1);
                }else if(res.size()>r-l+1){
                        res=s.substr(l, r-l+1);
                }
                cnt[s[l]]--;
                if(cnt[s[l]]<cnt2refer[s[l]]){
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

