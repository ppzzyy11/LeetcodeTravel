/*
 * 365.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    //unordered_map<pair<int, int>, bool, pair_hash> rec;
    unordered_set<pair<int, int> , pair_hash> rec;
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity<targetCapacity){
            return false;
        }
        if(targetCapacity%2==1&&jug1Capacity%2==0&&jug2Capacity%2==0){
            return false;
        }
        return dfs(jug1Capacity, 0, jug2Capacity, 0, targetCapacity);
    }

    bool dfs(int jug1C, int jug1, int jug2C, int jug2, int targetC){

        if(jug2<0||jug1<0||jug1>jug1C||jug2>jug2C){
            return false;
        }
        pair<int, int> coor=make_pair(jug1, jug2);
        if(rec.count(coor)){
            return false;
        }
        rec.insert(coor);

        if(jug1+jug2==targetC||jug1==targetC||jug2==targetC){
            return true;
        }

        return dfs(jug1C, jug1C, jug2C, jug2, targetC)||
            dfs(jug1C, jug1, jug2C, jug2C, targetC)||
            dfs(jug1C, 0, jug2C, jug2, targetC)||
            dfs(jug1C, jug1, jug2C, 0, targetC)||
            dfs(jug1C, 0, jug2C, jug1+jug2, targetC)||
            dfs(jug1C, jug1+jug2, jug2C, 0, targetC)||
            dfs(jug1C, jug1C, jug2C, jug2-(jug1C-jug1), targetC)||
            dfs(jug1C, jug1-(jug2C-jug2), jug2C, jug2C, targetC);
    }
};





int main(){
    return 0;
}

