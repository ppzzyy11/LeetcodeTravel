/*
 * 8.cpp
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
    int myAtoi(string s) {
        int i=0;
        long res=0;
        bool neg=false;

        int idx=0;
        while(idx<s.size()&&s[idx]==' '){
            idx++;
        }

        if(idx<s.size()&&( s[idx]=='-' ||s[idx]=='+')){
            neg=(s[idx]=='-');
            idx++;
        }

        //begin NUM
        while(idx<s.size()&&s[idx]>='0'&&s[idx]<='9'){
            res=res*10+(s[idx]-'0');
            if(neg){
                if(res>=abs((long)INT_MIN)){
                    return INT_MIN;
                }
            }else{
                if(res>=(long)INT_MAX){
                    return INT_MAX;
                }
            }
            idx++;
        }

        return neg?-res:res;

    }
};





int main(){
    return 0;
}

