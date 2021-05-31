/*
 * 187.cpp
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



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> res;


        unordered_map<string, int> rec;
        string substr=s.substr(0, 10);
        rec[substr]++;
        for(int i=10; i<s.size(); i++){
            substr=substr.substr(1)+s[i];
            rec[substr]++;
            if(rec[substr]==2){
                res.push_back(substr);
            }

        }
        return res;
    }
};





int main(){
    return 0;
}

