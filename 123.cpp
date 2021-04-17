/*
 * 123.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
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

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0, dp1, dp2, dp3;
        dp0=dp1=dp2=dp3=INT_MIN;
        for(int i=0; i<prices.size(); i++){
            if(i>2){
                dp3=max(dp3, dp2+prices[i]);
            }
            if(i>1){
                dp2=max(dp2, dp1-prices[i]);
            }
            if(i>0){
                dp1=max(dp1, dp0+prices[i]);
            }
            if(i==0){
                dp0=-prices[i];
            }else {
                dp0=max(dp0, -prices[i]);
            }
        }

        return max(0,max(dp1, dp3));
    }
};




int main(){
    return 0;
}

