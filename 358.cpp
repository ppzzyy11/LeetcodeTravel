/*
 * 358.cpp
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



class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> left(26, 0);
        for(const char& ch: s){
            left[ch-'a']++;
        }

        priority_queue<pair<int, int>> heap;
        for(int i=0; i<26; i++){
            if(left[i]>0)
            heap.push(make_pair(left[i], i));
        }

        queue<char> window;
        string res="";

        while(!heap.empty()){
            int max=heap.top().second;
            heap.pop();

            window.push(max);
            left[max]--;
            res+='a'+max;

            if(window.size()>=k){
                int m=window.front();
                window.pop();
                if(left[m]>0){
                    heap.push(make_pair(left[m], m));
                }
            }
        }

        return res.size()<s.size()?"":res;

    }
};





int main(){
    return 0;
}

