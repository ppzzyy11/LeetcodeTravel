/*
 * 249.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> rec;
        for(const string& str: strings){
            rec[shift(str)].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it=rec.begin(); it!=rec.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }

    string shift(string str){
        if(str.size()==0){
            return "";
        }
        char mini=str[0];
        mini=mini-'a';
        for(int i=0; i<str.size(); i++){
            int num=str[i]-'a';
            num-=mini;
            num=(num+26)%26;
            str[i]='a'+num;
        }
        return str;
    }
};





int main(){
    return 0;
}

