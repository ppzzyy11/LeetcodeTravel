/*
 * 394.cpp
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
    string decodeString(string str) {
        stack<string> st;
        int s=0;
        int e=0;
        while(s<str.size()){
            if(str[s]>='0'&&str[e]<='9'){
                e=s;
                while(e<str.size()&&str[e]<='9'&&str[s]>='0'){
                    e++;
                }

                string num=str.substr(s, e-s);
                st.push(num);
            }else if(str[s]=='['){
                ;
                e=s+1;
            }else if(str[s]==']'){
                string pattern=st.top();
                st.pop();
                string num=st.top();
                st.pop();
                int n=stoi(num);
                string res="";
                while(n-->0){
                    res+=pattern;
                }
                if(st.size()==0){
                    st.push(res);
                }else{
                    string top=st.top();
                    if(top[0]>='a'&&top[0]<='z'){
                        st.pop();
                        st.push(top+res);
                    }else{
                        st.push(res);
                    }

                }
                e=s+1;
            }else{
                e=s;
                while(e<str.size()&&str[e]>='a'&&str[e]<='z'){
                    e++;
                }
                string substr=str.substr(s, e-s);
                if(st.size()){
                    string top=st.top();
                    if(top[0]>='a'&&top[0]<='z'){
                        st.pop();
                        st.push(top+substr);
                    }else{
                        st.push(substr);
                    }
                }else{
                    st.push(substr);
                }

            }
            s=e;
        }

        return st.top();

    }

};





int main(){
    return 0;
}

