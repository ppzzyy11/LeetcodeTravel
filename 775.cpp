/*
 * 775.cpp
 * Copyright (C) 2021-04-27 pzy <pzy@pzy-B250M-Wind>
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
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(abs(i-nums[i])>1){
                return false;
            }
        }
        return true;
    }
};

class SolutionBruteForce {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]>nums[j]){
                    return false;
                }
            }
        }
        return true;
    }
};





int main(){
    return 0;
}

