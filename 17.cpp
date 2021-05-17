/*
 * 17.cpp
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
    vector<string> digit2char{
        "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"

    };
public:
    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> res;
        // if(digits.)
        recur(res, path, digits, 0);
        return res;
    }

    void recur(vector<string>& res, string& path, const string& digits, int idx){
        if(idx==digits.size()){
            if(path.size()!=0)
                 res.push_back(path);
            return ;
        }

        for(char ch: digit2char[digits[idx]-'0']){
            path=path+ch;
            recur(res, path, digits, idx+1);
            path.pop_back();
        }

    }
};





int main(){
    return 0;
}

