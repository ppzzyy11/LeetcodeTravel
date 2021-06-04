/*
 * 318.cpp
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
    unordered_map<string, int> rec;
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if((str2inth(words[i])&str2inth(words[j]))==0){
                    res=max(res, (int)(words[i].size()*words[j].size()));
                }
            }
        }
        return res;
    }

    inline int str2inth(const string& str){
        if(rec.count(str)){
            return rec[str];
        }
        int res=0;
        for(const char& ch: str){
            res|=1<<(ch-'a');
        }
        return rec[str]=res;
    }

};





int main(){
    return 0;
}

