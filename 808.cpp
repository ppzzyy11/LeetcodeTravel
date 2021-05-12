/*
 * 808.cpp
 * Copyright (C) 2021-05-12 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

class Solution {
    unordered_map<pair<long, long>, double, pair_hash> rec;

public:
    double soupServings(int n) {
        if(n>500 * 25){
            return 1;
        }
        return getRate(n, n);
    }

    //return the empty rate
    double getRate(int a, int b ){
        if(a<=0&&b>0){
            return 1.0;
        }
        if(a<=0&&b<=0){
            return 0.5;
        }

        if(b<=0){
            return 0.0;
        }

        pair<long, long> idx=make_pair(a, b);

        if(rec.count(idx)!=0){
            return rec[idx];
        }

        return rec[idx]=0.25*(getRate(a-100, b)+getRate(a-75, b-25)+getRate(a-50, b-50)+getRate(a-25, b-75));
    }
};





int main(){
    Solution s;

    cout<<s.soupServings(660295675);
    return 0;
}

