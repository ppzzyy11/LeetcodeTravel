/*
 * 267.cpp
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
    vector<string> generatePalindromes(string s) {
        vector<int> cnt(26, 0);
        for(char ch: s){
            cnt[ch-'a']++;
        }
        vector<string> res;
        string pre;
        string suf;
        backtracking(res, pre, suf, s.size(), cnt);
        return res;
    }

    void backtracking(vector<string>& res, string& pre, string& suf, int n, vector<int>& cnt){
        if(pre.size()+suf.size()==n){
            reverse(suf.begin(), suf.end());
            res.push_back(pre+suf);
            reverse(suf.begin(), suf.end());
            return ;
        }
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]>=2){
                cnt[i]-=2;
                pre+='a'+i;
                suf+='a'+i;

                backtracking(res, pre, suf, n, cnt);
                pre.pop_back();
                suf.pop_back();

                cnt[i]+=2;
            }else if(cnt[i]==1&&pre.size()+suf.size()+1==n){
                pre+='a'+i;
                backtracking(res, pre, suf, n, cnt);
                pre.pop_back();
            }
        }

    }

};





int main(){
    return 0;
}

