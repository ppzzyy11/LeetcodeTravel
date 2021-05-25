/*
 * 335.cpp
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
    unordered_set<pair<int,int>, pair_hash> rec;
public:
    bool isSelfCrossing(vector<int>& distance) {
        int x, y;
        x=y=0;

        rec.insert(make_pair(0, 0));
        for(int i=0; i<distance.size(); i++){
            int d=distance[i];
            while(d-->0){
                if(i%4==0){
                    y++;
                }else if(i%4==1){
                    x--;
                }else if(i%4==2){
                    y--;
                }else if(i%4==3){
                    x++;
                }
                pair<int, int> coor=make_pair(x, y);
                if(rec.count(coor)){
                    return true;
                }
                rec.insert(coor);
            }
        }

        return false;
    }
};





int main(){
    return 0;
}

