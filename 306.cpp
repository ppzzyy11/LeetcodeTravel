/*
 * 306.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    bool isAdditiveNumber(string num) {
        vector<long> nums;
        return backtracking(num, 0, nums);
    }

    bool backtracking(const string& num, long idx, vector<long>& nums){
        if(idx==num.size()){
            return nums.size()>=3;
        }

        int upper=1;
        if(nums.size()>=2){
            int sum=nums[nums.size()-1]+nums[nums.size()-2];
            while(sum){
                upper++;
                sum/=10;
            }
        }else{
            upper=( num.size()-idx +1)/2;
        }
        for(long e=idx; e<idx+upper; e++){
            if(e!=idx&&num[idx]=='0'){
                break;
            }
            string substr=num.substr(idx, e-idx+1);
            long n=stol(substr);
            if(nums.size()>=2){
                if(n!=nums[nums.size()-1]+nums[nums.size()-2]){
                    continue;
                }
            }else{
                ;
            }
            nums.push_back(n);
            bool res= backtracking(num, e+1, nums);
            nums.pop_back();
            if(res==true){
                return true;
            }

        }

        return false;
    }
};





int main(){
    return 0;
}

