/*
 * 288.cpp
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



class ValidWordAbbr {
    unordered_map<string, string> rec;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i=0; i<dictionary.size(); i++){
            string abbr=getAbbr(dictionary[i]);
            if(rec.count(abbr)&&rec[abbr]!=dictionary[i]){
                rec[abbr]="";
            }else{
                rec[abbr]=dictionary[i];
            }
        }
    }

    bool isUnique(string word) {
        string abbr=getAbbr(word);
        if(rec.count(abbr)==0){
            return true;
        }
        if(rec[abbr]==""){
            return false;
        }
        return rec[abbr]==word;
    }

    inline string getAbbr(string str){
        if(str.size()<=2){
            return str;
        }
        return str[0]+to_string(str.size()-2)+str.back();
    }
};





int main(){
    return 0;
}

