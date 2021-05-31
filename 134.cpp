/*
 * 134.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int cur_s=0;
        int s=0;
        int cur_sum=0;
        int sum=0;
        vector<int> minus(n, 0);
        for(int i=0; i<n*2; i++){
            cur_sum+=gas[i%n]-cost[i%n];
            if(cur_sum>sum){
                s=cur_s;
                sum=cur_sum;
            }else if(cur_sum<0){
                cur_s=(i+1)%n;
                cur_sum=0;
            }
        }
        //cout<<s<<endl;

        //start from s,
        cur_s=s;
        cur_sum=0;
        for(int i=0; i<n; i++){
            cur_sum+=gas[(s+i)%n]-cost[(s+i)%n];
            if(cur_sum<0){
                return -1;
            }
        }

        return s;
    }
};





int main(){
    Solution so;
    //so.canCompleteCircuit({1,2,3,4,5,0,1}, {3,4,5,1,2,100,1});
    return 0;
}

