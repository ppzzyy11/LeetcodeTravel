/*
 * 532.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=0;
        unordered_map<int, int>cnt;
        for(int i=0; i<nums.size(); i++){
            //just calculate the smaller one
            cnt[nums[i]]++;
            if(k==0&&cnt[nums[i]]==2){
                res++;
            }else if(k!=0){
                if(cnt[nums[i]]==1&&cnt[nums[i]-k]!=0){
                        res++;
                }
            }

        }


        return res;

    }
};





int main(){
    return 0;
}

