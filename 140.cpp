/*
 * 140.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //(x,100*y)=possible arrangemtns
        unordered_map<string, vector<string>> mem;
        unordered_set<string> rec;

        for(auto& word: wordDict){
            rec.insert(word);
        }
        return geneAns(s, mem, rec);
    }

    vector<string> geneAns(const string& str, unordered_map<string, vector<string>>& mem, unordered_set<string>& dict){
        if(mem.count(str)){
            return mem[str];
        }
        unordered_set<string> rec;
        string substr="";
        for(int i=0; i<str.size(); i++){
            substr+=str[i];
            if(dict.find(substr)!=dict.end()){
                vector<string> pos = geneAns(str.substr(i+1), mem, dict);
                //combime substr + auto p: pos
                if(i==str.size()-1){
                    rec.insert(substr);
                }
                for(auto p:pos){
                    rec.insert(substr+' '+p);
                }
            }
        }
        vector<string> res(rec.begin(), rec.end());
        return mem[str]=res;

    }

    vector<string> transRes(const vector<vector<string>>& mat){
        vector<string> res;
        return res;
    }


};





int main(){
    return 0;
}

