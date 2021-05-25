/*
 * 397.cpp
 * Copyright (C) 2021-05-24 pzy <pzy@pzy-B250M-Wind>
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
    unordered_map<long, int> rec;
public:
    int integerReplacement(long n) {
        if(rec.count(n)){
            return rec[n];
        }
        if(n==1){
            return 0;
        }
        return rec[n]=(n%2==0?integerReplacement(n/2):min(integerReplacement(n-1),integerReplacement(n+1)))+1;
    }
};





int main(){
    return 0;
}

