/*
 * 621.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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

struct MyCompare{
    bool operator()(pair<char, int>& a, pair<char, int>& b){
        return a.second<b.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //in cooldown
        queue<pair<char, int>> que;

        vector<pair<char, int>> heap;

        vector<int> cnt(26,0);
        for(char ch: tasks){
            cnt[ch-'A']++;
        }

        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]!=0){
                heap.push_back(make_pair(i+'A', cnt[i]));
                push_heap(heap.begin(), heap.end(),MyCompare);
            }
        }
    }


};





int main(){
    return 0;
}

