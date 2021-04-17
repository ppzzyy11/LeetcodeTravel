/*
 * 189.cpp
 * Copyright (C) 2021-04-16 pzy <pzy@pzy-B250M-Wind>
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
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        int cnt=0;
        for(int s=0; s<=k;s++){
            if(cnt==nums.size()){
                break;
            }
            int idx=s;
            int curNum=nums[idx];
            do{
                int nxt_idx=(idx+k)%nums.size();
                swap(nums[nxt_idx], curNum);
                idx=nxt_idx;
                cnt++;
            }while(idx!=s);
        }
    }
};

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};





int main(){
    return 0;
}

