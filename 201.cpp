/*
 * 201.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    int rangeBitwiseAnd(int left, int right) {
        int shift=0;
        while(left<right){
            left>>=1;
            right>>=1;
            shift++;
        }
        return left<<shift;
    }
};





int main(){
    return 0;
}

