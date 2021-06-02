/*
 * 425.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



//reduce get prefix time complexity
class Solution {
    unordered_map<string, vector<string>> prefix2words;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for(const string& word: words){
            string prefix="";
            prefix2words[prefix].push_back(word);
            for(int i=0; i<word.size(); i++){
                prefix+=word[i];
                prefix2words[prefix].push_back(word);
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        backtracking(res, path, words[0].size());
        return res;
    }

    void backtracking(vector<vector<string>>& res, vector<string>& path, int n){
        //edge
        if(path.size()==n){
            res.push_back(path);
            return ;
        }

        string prefix=getPrefix(path,path.size());
        vector<string> words=getWordsWithPrefix(prefix);

        //enum
        for(int i=0; i<words.size(); i++){
            path.push_back(words[i]);
            backtracking(res, path, n);
            path.pop_back();
        }

    }

    string getPrefix(const vector<string>& path, int j){
        string res="";
        for(int i=0; i<path.size(); i++){
            res+=path[i][j];
        }
        return res;
    }

    vector<string> getWordsWithPrefix(const string& prefix){
        return prefix2words[prefix];
    }
};

class SolutionTLE {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        vector<string> path;
        backtracking(res, path, words,  words[0].size());
        return res;
    }

    void backtracking(vector<vector<string>>& res, vector<string>& path, const vector<string>& words, int n){
        //edge
        if(path.size()==n){
            res.push_back(path);
            return ;
        }

        string prefix=getPrefix(path,path.size());
        //enum
        for(int i=0; i<words.size(); i++){

            //cut branches
            if(valid(prefix, words[i])){
                path.push_back(words[i]);
                if(valid2(path, words)){
                    backtracking(res, path, words,  n);
                }
                path.pop_back();
            }
        }

    }

    bool valid(const string& prefix, const string& word){
        int i=0, j=0;
        while(i<prefix.size()){
            if(j==word.size()){
                return false;
            }
            if(prefix[i]!=word[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }

    bool valid2(const vector<string>& path, const vector<string>& words){
        for(int j=0; j<path.size(); j++){
            string prefix=getPrefix(path, j);
            if(!exist(prefix, words)){
                return false;
            }
        }
        return true;
    }

    bool exist(const string& prefix, const vector<string>& words){
        for(const string& word: words){
            if(valid(prefix, word)){
                return true;
            }
        }
        return false;
    }

    string getPrefix(const vector<string>& path, int j){
        string res="";
        for(int i=0; i<path.size(); i++){
            res+=path[i][j];
        }
        return res;
    }
};





int main(){
    return 0;
}

