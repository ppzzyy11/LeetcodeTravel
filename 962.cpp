/*
 * 962.cpp
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
        int maxWidthRamp(vector<int>& A) {
            vector<int> idx;
            for(int i=0; i<A.size(); i++){
                idx.push_back(i);
            }
            sort(idx.begin(), idx.end(), [&](const int&a, const int& b){
                    if(A[a]!=A[b]) {
                        return A[a]<A[b];
                    }
                    // Very important, otherwise A[i]=A[j], i<j, we can put j before i causing losing in focus.
                    return a<b;
                    });
            int res=0;

            int tmp=INT_MAX;
            for(int i=0; i<idx.size(); i++){
                if(i!=0)
                    res=max(res, idx[i]-tmp);
                tmp=min(tmp, idx[i]);
            }

            return res;
        }
};



int main(){
    return 0;
}

