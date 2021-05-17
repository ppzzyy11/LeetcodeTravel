/*
 * 49.cpp
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rec;
        for(const string& str: strs ){
            string cpy=str;
            sort(cpy.begin(), cpy.end());
            rec[cpy].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it=rec.begin(); it!=rec.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};





int main(){
    return 0;
}

