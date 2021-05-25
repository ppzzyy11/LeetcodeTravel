/*
 * 400.cpp
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
public:
    int findNthDigit(int n) {
        long minus=9;
        long cnt=1;
        int num=0;
        while(n>minus*cnt){
            n=n-minus*cnt;
            num+=minus;
            minus*=10;
            cnt++;
        }
        num+=(n/cnt)+(n%cnt==0?0:1);
        n=(n-1+cnt)%cnt;
        vector<int> digits=getDigits(num);
        return digits[n];
    }

    vector<int> getDigits(int num){
        vector<int> res;
        while(num>0){
            res.push_back(num%10);
            num=num/10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};





int main(){
    return 0;
}

