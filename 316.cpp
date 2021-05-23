/*
 * 316.cpp
 * Copyright (C) 2021-05-18 pzy <pzy@pzy-B250M-Wind>
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
    string removeDuplicateLetters(string s) {
        stack<char> ch;
        vector<int> remains(26, 0);
        vector<bool> visited(26, false);
        stack<char> st;
        for(char ch: s){
            remains[ch-'a']++;
        }

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            remains[ch-'a']--;

            while(st.size()!=0&&st.top()>s[i]){
                if(remains[st.top()-'a']>0&&visited[ch-'a']==false){
                    visited[st.top()-'a']=false;
                    st.pop();
                }else{
                    break;
                }
            }

            if(visited[ch-'a']==false){
                st.push(ch);
                visited[ch-'a']=true;
            }

        }

        string res="";
        while(st.size()){
            res=st.top()+res;
            st.pop();
        }


        return res;
    }
};





int main(){
    return 0;
}

