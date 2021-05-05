/*
 * 338.cpp
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;

//DP
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int idx=0;
        int top=0;
        for(int i=0; i<=num; i++){
            if(i==0){
                res.push_back(0);
                idx=0;
                top=1;
                continue;
            }

            res.push_back(res[idx]+1);
            idx++;
            if(idx==top){
                top=res.size();
                idx=0;
            }
        }
        return res;
    }
};

class SolutionBF {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0; i<=num; i++){
            res.push_back(count1(i));
        }
        return res;

    }

    int count1(int num){
        int res=0;
        while(num){
            res+=(num&1);
            num=num>>1;
        }
        return res;

    }
};





int main(){
    return 0;
}

