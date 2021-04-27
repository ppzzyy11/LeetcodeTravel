/*
 * 229.cpp
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
    vector<int> majorityElement(vector<int>& nums) {
        //

        int candicate1 = nums[0];
        int candicate2 = nums[0];
        int count1 = 0;
        int count2 = 0;


        for(auto num :nums){
            if(candicate1==num){
                count1++;
                continue;
            }

            if(candicate2==num){
                count2++;
                continue;
            }


            if(count1==0){
                candicate1=num;
                count1++;
                continue;
            }

            if(count2==0){
                candicate2=num;
                count2++;
                continue;
            }

            count1--;
            count2--;
        }


        count1=0;
        count2=0;

        for(int num: nums){
            if(num==candicate1){
                count1++;
            }else if(num==candicate2){
                count2++;
            }
        }

        vector<int> res;
        if(count1>nums.size()/3){
            res.push_back(candicate1);
        }
        if(count2>nums.size()/3){
            res.push_back(candicate2);
        }

        return res;
    }
};





int main(){
    return 0;
}

