/*
 * 161.cpp
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
    bool isOneEditDistance(string s, string t) {

        if(abs((int)s.size()-(int)t.size())>1){
            return false;
        }

        int idx=0;

        while(idx<s.size()&&idx<t.size()&&s[idx]==t[idx]){
            idx++;
        }

        return same(s, idx+1, t, idx+1)||same(s, idx, t, idx+1)||same(s, idx+1, t, idx);
    }

    bool same(const string& str1, int idx1, const string& str2, int idx2){
        while(idx1<str1.size()&&idx2<str2.size()){
            if(str1[idx1]!=str2[idx2]){
                return false;
            }
            idx1++;
            idx2++;
        }
        return str1.size()==idx1&&str2.size()==idx2;
    }
};





int main(){
    return 0;
}

