/*
 * 179.cpp
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
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int num1, int num2){
                string str1=to_string(num1)+to_string(num2);
                string str2=to_string(num2)+to_string(num1);

                return str1>str2;

                });

        string res="";
        for(const int num: nums){
            res+=to_string(num);
        }

        int idx=0;
        while(idx<res.size()-1&&res[idx]=='0'){
            idx++;
        }
        res=res.substr(idx);

        return res;
    }
};





int main(){
    return 0;
}

