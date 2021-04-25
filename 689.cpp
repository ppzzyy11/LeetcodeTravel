/*
 * 689.cpp
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sum(0);
        int cur_sum=0;
        for(int i=0; i<k; i++){
            cur_sum+=nums[i];
        }

        sum.push_back(cur_sum);
        for(int i=k; i<nums.size(); i++){
            cur_sum-=nums[i-k];
            cur_sum+=nums[i];
            sum.push_back(cur_sum);
        }


        vector<int> left(0);
        vector<int> right(0);
        int idx=0;
        for(int i=0; i<sum.size(); i++){
            if(i==0||sum[i]>sum[idx]){
                idx=i;
            }
            left.push_back(idx);
        }

        idx=sum.size()-1;
        for(int i=sum.size()-1; i>=0; i--){
            //sum[idx]<=sum[i], return the lexicographically smallest one.
            if(i==sum.size()-1||sum[idx]<=sum[i]){
                idx=i;
            }
            right.push_back(idx);
        }
        //right should begin from the right
        reverse(right.begin(), right.end());

        vector<int> res{left[0], k, right[2*k]};
        for(int i=k+1; i<sum.size()-k; i++){
            if(sum[res[0]]+sum[res[1]]+sum[res[2]]<sum[left[i-k]]+sum[i]+sum[right[i+k]]){
                res={left[i-k],i,right[i+k]};
            }
        }
        return res;

    }
};


int main(){
    return 0;
}

