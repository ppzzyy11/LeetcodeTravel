/*
 * 688.cpp
 * Copyright (C) 2021-05-10 pzy <pzy@pzy-B250M-Wind>
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
    unordered_map<pair<int,int>, unordered_map<int, double>, pair_hash> rec;
public:
    double knightProbability(int n, int k, int row, int column) {

        if(row<0||column<0||row>=n||column>=n){
            return 0;
        }
        pair<int, int> coor=make_pair(row, column);
        if(rec.count(coor)!=0&&rec[coor].count(k)!=0)        {
            return rec[coor][k];
        }
        if(k==0){
            return rec[coor][k]=1.0;
        }
        return rec[coor][k]=(
                knightProbability(n, k-1, row-2, column-1)+
                knightProbability(n, k-1, row-2, column+1)+

                knightProbability(n, k-1, row+2, column+1)+
                knightProbability(n, k-1, row+2, column-1)+

                knightProbability(n, k-1, row-1, column+2)+
                knightProbability(n, k-1, row-1, column-2)+

                knightProbability(n, k-1, row+1, column-2)+
                knightProbability(n, k-1, row+1, column+2)+
                0
                )/8.0;

    }

};





int main(){
    return 0;
}

