/*
 * 472.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
    bool concatenated(const string& str, unordered_set<string>& rec){
        if(rec.count(str)!=0){
            return true;
        }
        string pre="";
        for(const char& ch: str){
            pre+=ch;
            if(rec.count(pre)!=0){
                if(concatenated(str.substr(pre.size()), rec)==true){
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& str1, const string& str2){return str1.size()<str2.size();});
        vector<string> res;
        unordered_set<string> rec;
        for(const string& word: words){
            if(concatenated(word, rec)){
                res.push_back(word);
            }
            rec.insert(word);
        }

        return res;
    }
};





int main(){
    return 0;
}

