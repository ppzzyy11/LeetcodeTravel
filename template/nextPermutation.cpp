/*
 * nextPermutation.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    void nextPermutation(vector<int>& nums) {
        int i =0;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }

        if(i==-1){
            reverse(nums.begin(), nums.end());
        }else{
            for(int j=nums.size()-1;j>=i+1; j--){
                if(nums[i]<nums[j]){
                    swap(nums[i], nums[j]);
                    reverse(nums.begin()+i+1, nums.end());
                    break;
                }
            }
        }
    }
};





int main(){
    return 0;
}

