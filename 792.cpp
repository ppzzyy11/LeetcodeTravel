/*
 * 792.cpp
 * Copyright (C) 2021-04-27 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> dp;
        generateRec(s, dp);
        int res =0;
        for(auto& word: words){
            if(check(dp, word)){
                res++;
            }
        }
        return res;
    }

    void generateRec(const string& s, vector<vector<int>>& dp){
        dp.resize(s.size()+1, vector<int>(26, -1));
        vector<int> idx(26,-1);
        for(int i=s.size(); i>=0; i--){
            dp[i]=idx;
            if(i!=0)
                idx[s[i-1]-'a']=i;
        }
    }

    bool check(const vector<vector<int>>& dp, const string& word){
        int i=0;
        int idx =0;
        while(i<word.size()&&idx!=-1){
            idx=dp[idx][word[i]-'a'];
            i++;
        }
        return i==word.size()&&idx!=-1;
    }
};


class SolutionHash {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0;
        vector<int> base = statistic(s);
        for(auto word: words){
            vector<int> test = statistic(word);
            if(check(base, test)&&match(s, word)){
                res++;
            }
        }
        return res;
    }

    vector<int> statistic(const string& s){
        vector<int> cnt(26,0);
        for(char ch:s){
            cnt[ch-'a']++;
        }
        return cnt;
    }


    bool check(const vector<int>& base, const vector<int>& test){
        for(int i=0; i<base.size(); i++){
            if(test[i]>base[i]){
                return false;
            }
        }
        return true;
    }

    bool match(const string& s, const string& p){
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==p[j]){
                j++;
            }
            if(j==p.size()){
                return true;
            }
        }
        return false;
    }
};





int main(){
    return 0;
}

