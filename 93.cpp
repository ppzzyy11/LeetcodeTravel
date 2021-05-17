/*
 * 93.cpp
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
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        backtracking(res, path, s, 0);
        return res;
    }

    void backtracking(vector<string>& res, vector<string>& path,  const string& s, int idx){
        if(idx==s.size()){
            if(path.size()!=4){
                return ;
            }
            //assert that path are valid
            string tmp="";
            for(const string& p: path){
                tmp=tmp+p+'.';
            }
            tmp.pop_back();
            res.push_back(tmp);
            return ;
        }
        if(path.size()==4){
            return ;
        }

        int i=idx;
        for(int j=i; j<=i+2&&j<s.size(); j++){
            string tmp=s.substr(i, j-i+1);
            if(tmp.size()>1&&tmp[0]=='0'){
                break;
            }
            int num=atoi(tmp.c_str());
            if(num>255){
                break;
            }

            path.push_back(tmp);
            backtracking(res, path, s, j+1);
            path.pop_back();
        }

    }

};





int main(){
    return 0;
}

