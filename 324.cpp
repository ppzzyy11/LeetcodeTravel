/*
 * 324.cpp
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
        void wiggleSort(vector<int>& nums) {
            int n=nums.size();
            sort(nums.begin(), nums.end());
            vector<int> bk = nums;
            int k=nums.size()-1;
            //(n+1)/2 and (n+1)/2-1 are put as far as possible.
            for(int i=0; 2*i+1<n; i++){
                nums[2*i+1]=bk[k--];
            }
            for(int i=0; 2*i<n; i++){
                nums[2*i]=bk[k--];
            }



        }
    };





int main(){
    return 0;
}

