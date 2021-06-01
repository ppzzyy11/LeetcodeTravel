/*
 * 320.cpp
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
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string path;
        backtracking(res, path, word, 0);
        return res;

    }

    void backtracking(vector<string>&res, string path, const string& word, int idx){
        if(idx==word.size()){
            res.push_back(path);
            return ;
        }
        if(path.size()!=0&&path.back()>='0'&&path.back()<='9'){

        }else{

            for(int e=word.size()-1; e>=idx; e--){
                backtracking(res, path+to_string(e-idx+1), word, e+1);
            }
        }

        backtracking(res, path+word[idx], word, idx+1);
    }

};





int main(){
    return 0;
}

