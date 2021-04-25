/*
 * 644.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
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
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int minV=INT_MAX, maxV=INT_MIN;
        for(auto num: nums){
            minV=min(num, minV);
            maxV=max(num, maxV);
        }

        double l=minV, r=maxV;
        double m=(l+r)/2, pre_m=INT_MAX;
        while(abs(m-pre_m)>0.00001){
            if(check(nums, k, m)){
                //find the maximum
                l=m;
            }else{
                r=m;
            }
            pre_m=m;
            m = (l+r)/2;
        }

        return m;
    }


    //can get the mid value, when subarray's length >= k
    bool check(const vector<int>& nums, int k, double mid){
        double sumi=0;
        double sumj=0;
        double minSumi=0;
        for(int i=0; i<k;i++){
            sumj+=nums[i]-mid;
        }

        if(sumj>=0){
            return true;
        }

        for(int i=k; i<nums.size(); i++){
            sumj+=nums[i]-mid;
            sumi+=nums[i-k]-mid;
            minSumi=min(minSumi, sumi);

            //[minI, j] is valid
            if(sumj>=minSumi){
                return true;
            }
        }

        return false;
    }
};





int main(){
    return 0;
}

