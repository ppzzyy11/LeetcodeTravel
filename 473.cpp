/*
 * 473.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
    bool makesquare(vector<int>& matchsticks) {
        long sum=0;
        for(const int& mat: matchsticks){
            sum+=mat;
        }
        if(sum%4){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        vector<long> sums(4, 0);
        return backtacking(sums, 0, matchsticks, sum/4);

    }

    bool backtacking(vector<long>& sums, int s, const vector<int>& matchsticks, const long top){
        if(s==matchsticks.size()){
            return sums[0]==sums[1]&&sums[1]==sums[2]&&sums[2]==sums[3];
        }

        for(int i=0; i<sums.size(); i++){
            sums[i]+=matchsticks[s];
            if(sums[i]<=top){
                if(backtacking(sums, s+1, matchsticks, top)){
                    return true;
                }
            }
            sums[i]-=matchsticks[s];
        }
        return false;
    }
};





int main(){
    return 0;
}

