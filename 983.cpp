/*
 * 983.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);

        unordered_set<int> rec;
        for(const auto& day: days){
            rec.insert(day);
        }

        for(int i=1; i<=365; i++){
            if(rec.count(i)!=0){
                dp[i]=dp[i-1]+min(costs[0], min(costs[1], costs[2]));
                dp[i]=min(dp[i], (i-7>=0?dp[i-7]:0)+costs[1]);
                dp[i]=min(dp[i], (i-30>=0?dp[i-30]:0)+costs[2]);
            }else{
                dp[i]=dp[i-1];
            }
        }

        return dp[365];
    }
};





int main(){
    return 0;
}

