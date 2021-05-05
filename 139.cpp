/*
 * 139.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> rec;
        for(auto word: wordDict){
            rec.insert(word);
        }

        vector<bool> dp(s.size(), false);

        for(int i=0; i<s.size(); i++){
            if(rec.count(s.substr(0, i+1))){
                dp[i]=true;
            }else{
                for(int j=0; j<i; j++){
                    if(dp[j]==true){
                        if(rec.count(s.substr(j+1, i-j))){
                            dp[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp.back();

    }
};





int main(){
    return 0;
}

