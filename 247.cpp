/*
 * 247.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    vector<string> findStrobogrammatic(int n) {
        vector<string> tmp;
        string path="";
        backtracking(tmp, path, 0, n);
        vector<string> res;
        for(auto t: tmp){
            string str=t;
            reverse(t.begin(), t.end());
            for(int i=0; i<t.size(); i++){
                if(t[i]=='6'){
                    t[i]='9';
                }else if(t[i]=='9'){
                    t[i]='6';
                }
            }
            if(n%2==1){
                res.push_back(str+'0'+t);
                res.push_back(str+'1'+t);
                res.push_back(str+'8'+t);
            }else{
                res.push_back(str+t);
            }
        }

        return res;

    }

    void backtracking(vector<string>& res, string path, int i, int n){
        if(i==n/2){
            res.push_back(path);
            return ;
        }

        if(i!=0)
            backtracking(res, path+'0', i+1, n);
        backtracking(res, path+'1', i+1, n);
        backtracking(res, path+'6', i+1, n);
        backtracking(res, path+'8', i+1, n);
        backtracking(res, path+'9', i+1, n);
    }

};





int main(){
    return 0;
}

