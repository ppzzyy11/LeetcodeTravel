/*
 * 271.cpp
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



class Codec {
    const int MOD=10;
    string hex2str(int num){
        string res="";
        int n=4;
        while(n--){
            res=(char)(num%MOD+'0')+res;
            num=num/MOD;
        }
        return res;
    }

    int str2hex(string num){
        int res=0;
        for(int i=0; i<num.size(); i++){
            res=(res*10)+((int)(num[i]-'0'));
        }
        return res;
    }
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        for(int i=0 ;i<strs.size(); i++){
            res+=hex2str(strs[i].size());
            res+=strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0; i<s.size(); i++){
            int len=str2hex(s.substr(i,4));
            res.push_back(s.substr(i+4, len));
            i=i+4+len-1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));





int main(){
    return 0;
}

