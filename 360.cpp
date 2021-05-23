/*
 * 360.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        multiset<int> rec;
        for(const int& num: nums){
            rec.insert(a*num*num+b*num+c);
        }
        vector<int> res(rec.begin(), rec.end());
        return res;

    }


};





int main(){
    return 0;
}

