/*
 * 411.cpp
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



class Solution {
    vector<string> new_dict;
    string res;
    string empty;
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        //filt words with different lengths
        for(const string& d: dictionary){
            if(d.size()==target.size())
                new_dict.push_back(d);
        }

        //
        if(new_dict.size()==0){
            return to_string(target.size());
        }

        vector<string> path;
        backtracking(target, 0, path);
        return res;

    }

    bool backtracking(const string& target, int idx, vector<string>& path){
        //edge
        if(idx==target.size()){
            if(valid(path)){
                string tmp="";
                for(const string& p: path){
                    tmp+=p;
                }
                if(res==""){
                    res=tmp;
                }else if(res.size()>tmp.size()){
                    res=tmp;
                }
                //vaild
                return false;
            }else{
                return false;
            }
        }
        int e=target.size()-1;
        if(path.size()!=0&&isDigit(path.back())){
                e=idx;
            }
        //try to generate abbreviation
        for(; e>=idx; e--){
            if(e==idx){
                path.push_back(empty+target[idx]);
                if(backtracking(target, idx+1, path)){
                    return true;
                }
                path.pop_back();
            }

            path.push_back(to_string(e-idx+1));
            backtracking(target, e+1, path);
            path.pop_back();
        }
        return false;
    }

    bool valid(const vector<string>& path){
        for(const string& word: new_dict){
            if(same(path, word)){
                return false;
            }
        }

        return true;
    }

    bool same(const vector<string>& path, const string& word){
        int ix=0, iy=0, j=0;
        for(int i=0; i<path.size(); i++){
            if(isDigit(path[i])){
                int num=stoi(path[i]);
                while(num-->0){
                    j++;
                }
            }else{
                if(j>=word.size()){
                    return false;
                }
                if(path[i][0]==word[j]){
                    j++;
                }else{
                    return false;
                }
            }
        }
        return j==word.size();
    }

    bool isDigit(const string& str){
        if(str.size()==0){
            return false;
        }

        return str[0]>='0'&&str[0]<='9';
    }
};





int main(){
    return 0;
}

