/*
 * 245.cpp
 * Copyright (C) 2021-04-17 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int l=0,r=0;
        int res=INT_MAX;
        vector<int> rec(2,0);
        while(r<wordsDict.size()){
            if(wordsDict[r]==word1){
                rec[0]++;
            }else if(wordsDict[r]==word2){
                rec[1]++;
            }
            r++;
            while(l<r&&check(rec, word1, word2)){
                res=min(res, r-l);
                if(wordsDict[l]==word1){
                    rec[0]--;
                }else if(wordsDict[l]==word2){
                    rec[1]--;
                }
                l++;
            }
        }
        return res-1;
    }

    bool check(const vector<int>& rec, const string& str1, const string& str2){
        if(str1==str2){
            return rec[0]>=2;
        }else{
            return rec[0]>=1&&rec[1]>=1;
        }
    }
};





int main(){
    return 0;
}

