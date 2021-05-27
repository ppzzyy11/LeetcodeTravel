/*
 * 301.cpp
 * Copyright (C) 2021-05-27 pzy <pzy@pzy-B250M-Wind>
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
    unordered_set<string> rec;
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove=0;
        int rightRemove=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')'){
                if(leftRemove==0){
                    rightRemove++;
                }
                if(leftRemove>0){
                    leftRemove--;
                }
            }else if(s[i]=='('){
                leftRemove++;
            }
        }
        string path="";
        dfs(s, 0, path, 0, 0, leftRemove, rightRemove);
        vector<string> res(rec.begin(), rec.end());
        return res;
    }

    void dfs(const string& s, int idx, string& path, int leftCnt, int rightCnt, int leftRemove, int rightRemove){
        if(idx==s.size()){
            if(leftCnt==rightCnt){
                rec.insert(path);
            }
            return ;
        }

        if(s[idx]==')'){
            if(leftCnt>rightCnt){
                //add ')'
                path+=s[idx];
                dfs(s, idx+1, path, leftCnt, rightCnt+1, leftRemove, rightRemove);
                path.pop_back();
            }
            //throw ')'
            if(rightRemove>0)
                dfs(s, idx+1, path, leftCnt, rightCnt, leftRemove, rightRemove-1 );
        }else if(s[idx]=='('){

            //add '('
            path+=s[idx];
            dfs(s, idx+1, path, leftCnt+1, rightCnt, leftRemove, rightRemove);
            path.pop_back();
            //throw '('
            if(leftRemove>0)
                dfs(s, idx+1, path, leftCnt, rightCnt, leftRemove-1, rightRemove );
        }else{
            path+=s[idx];
            dfs(s, idx+1, path, leftCnt, rightCnt, leftRemove, rightRemove);
            path.pop_back();
        }
    }
};





int main(){
    return 0;
}

