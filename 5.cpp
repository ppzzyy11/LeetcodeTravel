/*
 * 5.cpp
 * Copyright (C) 2021-05-03 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        for(int i=0; i<s.size(); i++){
            int len=0;
            //odd
            while(i-len>=0&&i+len<s.size()&&s[i-len]==s[i+len]){
                len++;
            }
            if(res.size()<2*len-1){
                res=s.substr(i-len+1, 2*len-1);
            }
            //even
            len=1;
            while(i-len>=0&&i+len-1<s.size()&&s[i-len]==s[i+len-1]){
                len++;
            }
            if(res.size()<2*len-2){
                res=s.substr(i-len+1, 2*len-2);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

