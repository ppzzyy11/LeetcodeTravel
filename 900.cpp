/*
 * 900.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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


class RLEIterator {
    vector<int> nums;
    int idx=0;//nums[idx]=n, nums[idx+1]=val
    int cnt=0;
public:
    RLEIterator(vector<int>& A) {
        nums=A;
    }

    int next(int n) {
        cnt+=n;
        while(idx<nums.size()&&cnt>nums[idx]){
            cnt-=nums[idx];
            idx=idx+2;
        }
        return idx<nums.size()?nums[idx+1]:-1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */





int main(){
    return 0;
}

