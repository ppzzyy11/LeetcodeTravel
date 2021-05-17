/*
 * 151.cpp
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
    string reverseWords(string s) {
        stack<string> st;
        generateStack(s, st);
        string res="";
        while(st.size()){
            res=res+st.top();
            st.pop();
            if(st.size()){
                res=res+' ';
            }
        }

        return res;
    }

    void generateStack(const string& s, stack<string>& st){
        int idx=0;
        while(idx<s.size()){
            if(s[idx]==' '){
                idx++;
                continue;
            }

            int j=idx;
            while(j<s.size()&&s[j]!=' '){
                j++;
            }
            //[i,j)
            st.push(s.substr(idx, j-idx));
            idx=j;

        }

    }
};





int main(){
    return 0;
}

