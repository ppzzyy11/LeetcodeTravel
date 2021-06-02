/*
 * 137.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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


//? why not work when debug on leetcode
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt1=0, cnt2=0, cnt3=0;
        for(int i=0; i<nums.size(); i++){
            //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
            // cnt3=cnt3^((cnt2&(cnt1&nums[i])));
            cnt2=cnt2^((cnt1&nums[i]));
            cnt1=cnt1^nums[i];
            cnt3=cnt1&cnt2;
            cnt1=cnt1&(~cnt3);
            cnt2=cnt2&(~cnt3);
        }
        //cout<<(cnt1&(~cnt2)|cnt3)<<endl;
        return cnt1;;
    }
};





int main(){
    Solution so;
    vector<int> nums{1,1,1,1,1,1,2};
    cout<<so.singleNumber(nums);
    return 0;
}

