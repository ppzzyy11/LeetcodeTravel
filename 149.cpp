/*
 * 149.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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


struct pair_hash{
    template <class T1, class T2>
        std::size_t operator() (std::pair<T1, T2> const &pair) const {
            std::size_t h1 =std::hash<T1>()(pair.first);
            std::size_t h2 =std::hash<T2>()(pair.second);

            return h1^h2;
        }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<pair<string, string>, int, pair_hash> cnt;
        int n=points.size();
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                pair<string, string> idx;

                if(x1==x2){
                    idx.first=to_string(INT_MAX);
                    idx.second=to_string(x1);
                }else{
                    idx.first=to_string(abs((double)(y2-y1)/(double)(x2-x1))).substr(0, 10);
                    idx.second=to_string(y1-x1*(double)(y2-y1)/(double)(x2-x1)).substr(0, 10);
                }

                cnt[idx]++;
                res=max(res, cnt[idx]);
            }
        }

        return (1+sqrt(1+8*res))/2;

    }
};





int main(){
    return 0;
}

