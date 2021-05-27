/*
 * 439.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
    string parseTernary(string exp) {
        stack<char> st;
        int s=0, e=0;
        reverse(exp.begin(), exp.end());
        while(s<exp.size()){
            char ch=exp[s];
            if(ch>='0'&&ch<='9'||ch=='T'||ch=='F'){
                while(st.size()&&st.top()=='?'){
                    char e=ch;
                    st.pop();
                    char left=st.top();
                    st.pop();
                    st.pop();
                    char right=st.top();
                    st.pop();
                    char res;
                    if(e=='F'){
                        res=right;
                    }else {
                        res=left;
                    }
                    ch=res;
                }
                st.push(ch);
            }else{
                st.push(ch);
            }
            s++;
        }
        string res="";
        res+=st.top();
        return res;
    }
};





int main(){
    return 0;
}

