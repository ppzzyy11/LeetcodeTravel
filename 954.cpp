/*
 * 954.cpp
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


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        //sort by absolute value
        sort(arr.begin(), arr.end(), [](const int& a, const int& b){return abs(a)<abs(b);});
        unordered_map<int, int> cnt;//value 2 times
        for(auto num: arr){
            cnt[num]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(cnt[arr[i]]){
                if(cnt[2*arr[i]]){
                    cnt[arr[i]]--;
                    cnt[2*arr[i]]--;
                }else{
                    return false;
                }

            }
        }
        return true;
    }
};





int main(){
    return 0;
}

