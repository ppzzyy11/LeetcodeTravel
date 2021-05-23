/*
 * 319.cpp
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
    int bulbSwitch(int n) {
        if(n==0){
            return 0;
        }
        int res=0;
        int i=1;
        while(i*i<=n){
            res++;
            i++;
        }
        return res;

    }
};





int main(){
    return 0;
}

