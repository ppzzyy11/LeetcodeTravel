/*
 * 38.cpp
 * Copyright (C) 2021-06-05 pzy <pzy@pzy-B250M-Wind>
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
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string pre=countAndSay(n-1);
        string res="";
        int s=0;
        while(s<pre.size()){
            int e=s;
            while(e<pre.size()&&pre[e]==pre[s]){
                e++;
            }
            res+=to_string(e-s)+pre[s];
            s=e;
        }
        return res;

    }


};





int main(){
    return 0;
}

