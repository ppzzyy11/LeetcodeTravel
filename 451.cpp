/*
 * 451.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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



bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    //???
    return p1.second<p2.second;
}

class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(256, 0);
        for(char ch: s){
            cnt[ch]++;
        }

        vector<pair<int, int>> heap;

        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]>0){
                heap.push_back(make_pair(i, cnt[i]));
                push_heap(heap.begin(), heap.end(), cmp);
            }
        }

        string res="";

        while(heap.size()){
            pair<int, int> top=heap[0];
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            int cnt=top.second;
            char ch=top.first;
            while(cnt-->0){
                res+=ch;
            }
        }

        return res;

    }
};





int main(){
    return 0;
}

