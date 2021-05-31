/*
 * 402.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    string removeKdigits(string num, int k) {
        while(k-->0){
            num=removeDigit(num);
        }
        while(num.size()&&num[0]=='0'){
            num=num.substr(1);
        }
        num=(num.size()==0?"0":num);
        return num;
    }

    string removeDigit(string num){
        int idx=0;
        while(idx+1<num.size()&&num[idx]<=num[idx+1]){
            idx++;
        }

        return num.substr(0, idx)+num.substr(idx+1);

    }
};





int main(){
    return 0;
}

