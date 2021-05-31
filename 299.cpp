/*
 * 299.cpp
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
    string getHint(string secret, string guess) {
        vector<int> cnt_s(10, 0);
        vector<int> cnt_g(10, 0);

        for(char ch: secret){
            cnt_s[ch-'0']++;
        }

        for(char ch: guess){
            cnt_g[ch-'0']++;
        }

        int a=0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                a++;
            }
        }

        int b=0;
        for(int i=0; i<10; i++){
            b+=min(cnt_s[i], cnt_g[i]);
        }
        b-=a;

        return to_string(a)+"A"+to_string(b)+"B";

    }
};





int main(){
    return 0;
}

