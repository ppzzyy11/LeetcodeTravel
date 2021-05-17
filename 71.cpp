/*
 * 71.cpp
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
    string simplifyPath(string path) {
        string res="";
        vector<string> st;
        vector<string> paths=split(path);
        for(const string& path: paths){
            if(path=="."){
                continue;
            }else if(path==".."){
                if(st.size()){
                    st.pop_back();
                }
            }else {
                st.push_back(path);
            }
        }
        for(int i=0; i<st.size(); i++){
            res=res+'/'+st[i];
        }

        return res.size()?res:"/";
    }

    vector<string> split(string& path){
        vector<string> res;
        int idx=0;
        char ch='/';
        while(idx<path.size()){
            if(path[idx]=='/'){
                idx++;
                continue;
            }
            int j=idx;
            while(j<path.size()&&path[j]!='/'){
                j++;
            }

            //path[j]=='/'
            res.push_back(path.substr(idx, j-idx));

            idx=j+1;
        }

        return res;

    }
};





int main(){
    return 0;
}

