/*
 * 280.cpp
 * Copyright (C) 2021-04-17 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++){
            if((i%2==0&&nums[i]>nums[i+1])||(i%2==1&&nums[i]<nums[i+1])){
                swap(nums[i], nums[i+1]);
            }
        }
    }
};





int main(){
    return 0;
}

