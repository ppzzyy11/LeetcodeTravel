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

public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        for(int i=0; i<strs.size(); i++){
            int len=strs[i].size();
            res+=(char)(len/256)+(char)(len%256);
            res+=strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0; i<s.size(); i++){
            int len=(int)s[i];
            len=(len<<4)+(int)s[i+1];
            i++;

            res.push_back(s.substr(i+1, len));
            i=i+len;
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





int main(){
    return 0;
}

