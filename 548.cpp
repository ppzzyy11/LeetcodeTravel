/*
 * 548.cpp
 * Copyright (C) 2021-04-21 pzy <pzy@pzy-B250M-Wind>
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
    bool splitArray(vector<int>& nums) {
        const int n=nums.size();
        if(n<7){
            return false;
        }

        // unordered_map<int, int> sum2idx;
        vector<int> sum;
        for(int i=0; i<n; i++){
            if(i==0){
                sum.push_back(nums[i]);
            }else{
                sum.push_back(nums[i]+sum[i-1]);
            }
        }


        //O(N^2)
        vector<pair<int,int>> iks;
        for(int i=1; i<n-5; i++){
            for(int k=i+4; k<n-1; k++){
                if(sum[n-1]-sum[k]==sum[i-1]){
                    iks.push_back(std::make_pair(i,k));
                }
            }
        }

        //O(N^2)
        for(auto ik: iks){
            int i=ik.first;
            int k=ik.second;
            for(int j=i+2; j<k-1; j++){
                if(sum[j-1]-sum[i]==sum[i-1]&&sum[k-1]-sum[j]==sum[i-1]){
                    return true;
                }
            }

        }


        return false;
    }
};





//Cut branches
class Solution2 {
public:
    bool splitArray(vector<int>& nums) {
        const int n=nums.size();
        if(n<7){
            return false;
        }
        //cut branches
        vector<int> sum;
        int maxV=INT_MIN, minV=INT_MAX;
        for(int i=0; i<n; i++){
            if(i==0){
                sum.push_back(nums[i]);
            }else{
                sum.push_back(nums[i]+sum[i-1]);
            }
            maxV=max(maxV, nums[i]);
            minV=min(minV, nums[i]);
        }

        //i, j, k
        //i,k to j
        for(int j=3;j<n-3; j++){
            //cut branches
            if(abs(sum[n-1]-sum[j]-sum[j-1])<=maxV-minV)
            {
                for(int i=1; i<j-1; i++){
                    if(sum[i-1]==sum[j-1]-sum[i]){
                        for(int k=j+1;k<n-1; k++){
                            if(sum[n-1]-sum[k]==sum[k-1]-sum[j]){
                                return true;
                            }
                        }
                    }
                }
            }

        }

        return false;

    }
};





int main(){
    return 0;
}

