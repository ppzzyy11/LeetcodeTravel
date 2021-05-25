/*
 * 396.cpp
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
    int maxRotateFunction(vector<int>& nums) {
        long long res=0;
        long long sum=0;
        long long n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            res+=i*nums[i];
        }

        long long tmp=res;
        for(int i=n-1; i>0; i--){
            tmp=tmp+sum-n*nums[i];
            res=max(tmp, res);
        }
        return res;
    }
};

class SolutionTLE {
public:
    int maxRotateFunction(vector<int>& nums) {
        long res=INT_MIN;
        for(int r=0; r<nums.size(); r++){
            long tmp=0;
            for(int i=0; i<nums.size(); i++){
                int idx=(i+r)%nums.size();
                tmp+=(nums[idx]);
            }
            res=max(res, tmp);
        }
        return res;
    }
};





int main(){
    return 0;
}

