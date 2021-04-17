/*
 * 128.cpp
 * Copyright (C) 2021-04-15 pzy <pzy@pzy-B250M-Wind>
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> rec;
        for(auto num:nums){
            rec.insert(num);
        }
        int res=0;

        for(auto num: nums){
            if(rec.find(num-1)==rec.end()){
                int curNum=num;
                int curLen=0;
                while(rec.find(curNum)!=rec.end()){
                    curNum++;
                    curLen++;
                    res=max(res, curLen);
                }
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

