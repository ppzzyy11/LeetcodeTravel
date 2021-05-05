/*
 * 357.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1, 0);
        for(int i =2; i<=n; i++){
            dp[i]=10*dp[i-1]+(pow(10, i-1)-pow(10, i-2)-dp[i-1])*(i-1);
        }
        int res=0;
        for(int i=0; i<=n; i++){
            res+=dp[i];
        }
        return pow(10, n)-res;
    }
};




int main(){
    return 0;
}

