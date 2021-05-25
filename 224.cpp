/*
 * 224.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
        stack<string> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s.substr(i, 1));
            }else if(s[i]==')'){
                string num=st.top();
                st.pop();
                st.pop();//pop "("
                st.push(num);
            }else if(s[i]==' '){
                continue;
            }else if(s[i]=='+'){
                st.push(s.substr(i,1));
            }else if(s[i]=='-'){
                st.push(s.substr(i,1));
            }else{//s[i] is [0, 9]
                int j=i;
                while(j<s.size()&&s[j]>='0'&&s[j]<='9'){
                    j++;
                }
                string num2=s.substr(i, j-i);
                if(st.top()=="("){
                    st.push(num2);
                }else{
                    string op=st.top();
                    st.pop();
                    string num1;
                    if(st.size()){
                        num1=st.top();
                        st.pop();
                    }else{
                        num1="0";
                    }
                    int n1=atoi(num1.c_str());
                    int n2=atoi(num2.c_str());
                    int n3;
                    if(op=="-"){
                        n3=n1-n2;
                    }else{
                        n3=n1+n2;
                    }
                    st.push(to_string(n3));
                }
            }
        }

        string top=st.top();
        return atoi(top.c_str());
    }
};





int main(){
    return 0;
}

