/*
 * 471.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    string encode(string str) {
        int n=str.size();
        vector<vector<string> > dp(n, vector<string>(n, ""));
        for(int s=0; s<n; s++){
            for(int e=s; e<n; e++){
                dp[s][e]=str.substr(s, e-s+1);
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<k; i++){
                //[i,j,k]
                for(int j=i; j<k; j++){


                }
            }
        }
    }
};


//tried to design a memorization as [start_index][len]=repeated_times



int main(){
    return 0;
}

