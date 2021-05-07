/*
 * 410.cpp
 * Copyright (C) 2021-05-07 pzy <pzy@pzy-B250M-Wind>
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
    int splitArray(vector<int>& nums, int m) {
        long left=nums[0];
        long right=0;
        for(int i=0; i<nums.size(); i++){
            left=max((long)nums[i], left);
            right+=nums[i];
        }

        //"l+1<r" style
        while(left+1<right){
            int mid=(right-left)/2+left;
            if(check(nums, mid, m)){
                right=mid;
            }else{
                left=mid;
            }
        }
        if(check(nums, left, m))
            return left;
        return right;

    }


    //whether nums can be split into m subarries and maximum of their sum is less than or equal to val
    //whether val is too big?
    bool check(const vector<int>& nums, int val, int m){
        //initialize cnt to 1
        int cnt=1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>val){
                cnt++;
                sum=nums[i];
            }
        }
        return cnt<=m;
    }
};



class SolutionDP {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<vector<long>> f(n+1, vector<long>(m+1, LONG_MAX));
        vector<long> sub(n+1, 0);

        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }


        return f[n][m];

    }
};




int main(){
    return 0;
}

