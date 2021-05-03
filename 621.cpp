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


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        int maxCnt=0;
        for(char ch: tasks){
            cnt[ch-'A']++;
            maxCnt=max(maxCnt, cnt[ch-'A']);
        }

        int max_cnt=0;
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i]==maxCnt){
                max_cnt++;
            }
        }
        return max((int)tasks.size(), (max_cnt+(maxCnt-1)*(n+1)));

    }


};





int main(){
    return 0;
}

