/*
 * 131.cpp
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        recur(res, path, s, 0);
        return res;
    }
    void recur(vector<vector<string>>& res, vector<string>& path, const string& s, int idx){
        if(idx==s.size()){
            res.push_back(path);
            return ;
        }

        for(int i=idx; i<s.size(); i++){
            string substr = s.substr(idx, i-idx+1);
            if(isPalindrome(substr)){
                path.push_back(substr);
                recur(res, path, s, i+1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& str){
        int l=0, r=str.size()-1;
        while(l<r){
            if(str[l++]!=str[r--]){
                return false;
            }
        }
        return true;

    }
};





int main(){
    return 0;
}

