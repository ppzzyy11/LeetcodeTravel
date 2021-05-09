/*
 * 413.cpp
 * Copyright (C) 2021-05-08 pzy <pzy@pzy-B250M-Wind>
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int diff=INT_MIN;
        int len=0;
        int res=0;
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]==diff){
                len++;
            }else{
                res+=getAns(len);
                diff=nums[i]-nums[i-1];
                len=2;
            }
        }
        res+=getAns(len);
        return res;

    }

    int getAns(int n){
        if(n<=0){
            return 0;
        }

        return (n-1)*(n-2)/2;
    }
};





int main(){
    return 0;
}

