/*
 * 484.cpp
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
    vector<int> findPermutation(string s) {
        int n=s.size();
        vector<int> res;
        for(int i=0; i<=n; i++){
            res.push_back(i+1);
        }

        int i=0;
        while(i<s.size()){
            int j=i;
            while(j<s.size()&&s[j]=='I'){
                j++;
            }
            i=j;

            while(j<s.size()&&s[j]=='D'){
                j++;
            }
            //?
            reverse(res.begin()+i, res.begin()+j+1);
            i=j;
        }

        return res;
    }
};





int main(){
    return 0;
}

