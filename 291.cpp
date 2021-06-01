/*
 * 291.cpp
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
    unordered_map<char, string> p2s;
    unordered_set<string> rec;
public:
    bool wordPatternMatch(string pattern, string s) {
        return match(pattern, 0, s, 0);
    }

    bool match(const string& pattern, int i, const string& str, int j){
        //edge
        if(i==pattern.size()&&str.size()==j){
            return true;
        }
        if(i>=pattern.size()||j>=str.size()){
            return false;
        }

        char p=pattern[i];
        if(p2s.count(p)==0){
            //try to assign pattern
            for(int len=1; j+len<=str.size(); len++){
                string s=str.substr(j, len);
                if(rec.count(s)!=0){
                    continue;
                }
                p2s[p]=s;
                rec.insert(s);
                if(match(pattern, i+1, str, j+len)){
                    return true;
                }
                p2s.erase(p2s.find(p));
                rec.erase(rec.find(s));
            }
        }else{

            //try to match
            string s=p2s[p];
            if(s.size()>str.size()){
                return false;
            }

            for(int k=0; k<s.size(); k++){
                if(s[k]!=str[j+k]){
                    return false;
                }
            }

            //match go on to next level
            return match(pattern, i+1, str, j+s.size());

        }
        return false;
    }
};





int main(){
    return 0;
}

