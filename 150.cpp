/*
 * 150.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(const string& token: tokens){
            if(isOperator(token)){
                int num2=stoi(st.top());
                st.pop();
                int num1=stoi(st.top());
                st.pop();

                if(token=="+"){
                    st.push(to_string(num1+num2));
                }else if(token=="-"){
                    st.push(to_string(num1-num2));
                } else if(token=="*"){
                    st.push(to_string(num1*num2));
                } else if(token=="/"){
                    st.push(to_string(num1/num2));
                }
            }else{
                st.push(token);
            }
        }

        return stoi(st.top());
    }

    bool isOperator(const string& str){
        return str=="+"||str=="-"||str=="*"||str=="/";
    }
};





int main(){
    return 0;
}

