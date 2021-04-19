/*
 * 370.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(auto update: updates){
            int s = update[0];
            int e = update[1];
            int v = update[2];

            res[s]+=v;
            if(e+1<length)
            {
                res[e+1]-=v;
            }

        }

        int tmp=0;
        for(int i=0; i<length; i++){
            tmp+=res[i];
            res[i]=tmp;
        }

        return res;
    }
};





int main(){
    return 0;
}

