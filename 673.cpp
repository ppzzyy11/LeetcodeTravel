/*
 * 673.cpp
 * Copyright (C) 2021-05-10 pzy <pzy@pzy-B250M-Wind>
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
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(len[i]==len[j]+1){
                        cnt[i]+=cnt[j];
                    }else if(len[i]<len[j]+1){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    }
                }
            }
        }

        int maxLen=0;
        for(auto& l:len){
            maxLen=max(maxLen, l);
        }
        int res=0;
        for(int i=0; i<n; i++){
            if(len[i]==maxLen){
                res+=cnt[i];
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

