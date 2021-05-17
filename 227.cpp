/*
 * 227.cpp
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
    int calculate(string s) {
        vector<string> strs=generate(s);
        stack<string> st;
        for(const string& str: strs){
            if(str=="+"||str=="-"){
                st.push(str);
            }else if(str=="*"||str=="/"){
                st.push(str);
            }else {
                if(st.size()&&(st.top()=="*"||st.top()=="/")){
                    string top=st.top();
                    st.pop();
                    int num1=atoi(st.top().c_str());
                    st.pop();
                    int num2=atoi(str.c_str());
                    int res;
                    if(top=="*"){
                        res=num1*num2;
                    }else if(top=="/"){
                        res=num1/num2;
                    }
                    st.push(to_string(res));
                }else{
                    st.push(str);
                }
            }
        }

        queue<string> que;
        while(st.size()!=0){
            que.push(st.top());
            st.pop();
        }
        while(que.size()!=0){
            st.push(que.front());
            que.pop();
        }
        while(st.size()!=1){
            int num1=atoi(st.top().c_str());
            st.pop();

            string op=st.top();
            st.pop();
            int num2=atoi(st.top().c_str());
            st.pop();

            int res;
            if(op=="+"){
                res=num1+num2;
            }else if(op=="-"){
                res=num1-num2;
            }
            st.push(to_string(res));
        }

        return atoi(st.top().c_str());

    }

    vector<string> generate(const string& s){
        vector<string> strs;
        int idx=0;
        while(idx<s.size()){
            if(s[idx]==' '){
                idx++;
                continue;
            }
            if(isDigit(s[idx])){
                int j=idx;
                while(j<s.size()&&isDigit(s[j])){
                    j++;
                }

                strs.push_back(s.substr(idx, j-idx));
                idx=j;
            }else {
                string tmp="";
                strs.push_back(tmp+s[idx]);
                idx++;
            }
        }
        return strs;
    }

    inline bool isDigit(char ch){
        return ch<='9'&&ch>='0';
    }
};





int main(){
    Solution s;
    s.calculate("1+3/2");
    return 0;
}

