/*
 * 837.cpp
 * Copyright (C) 2021-05-12 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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

using namespace std;


class Solution {
    unordered_map<int, double> rec;
public:
    double new21Game(int n, int k, int maxPts) {
        return getRate(0, n, k, maxPts,0);

    }

    double getRate(int sum, int target, int upper, int maxP, int dep){
        if(dep>10000){
            return 0;
        }
        if(rec.count(sum)!=0){
            return rec[sum];
        }
        if(sum>target){
            return 0;
        }
        if(sum<=target&&sum>=upper){
            return 1;
        }

        double res=0;
        for(int p=1; p<=maxP; p++){
            res+=getRate(sum+p, target, upper, maxP);
        }
        res=res/maxP;
        return rec[sum]=res;

    }
};





int main(){
    return 0;
}

