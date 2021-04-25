/*
 * 667.cpp
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
    vector<int> constructArray(int n, int k) {
        vector<int> res(0,0);
        vector<int> tail = generateK(k+1);
        for(int i=1; i<=n-k-1; i++){
            res.push_back(i);
        }
        for(auto num: tail){
            res.push_back(num+n-k-1);
        }
        return res;
    }

    vector<int> generateK(int k){
        vector<int> res;
        int l=1,r=k;
        while(l<=r){
            res.push_back(l++);
            if(l<=r){
                res.push_back(r--);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

