/*
 * 458.cpp
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



class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int l=1, r=buckets;
        int turn=minutesToTest/minutesToDie;
        while(l+1<r){
            int m=(l+r)/2;
            if(possible(buckets, turn, m)){
                r=m;
            }else {
                l=m;
            }
        }
        if(possible(buckets, turn, l)){
            return l;
        }
        return r;
    }

    bool possible(int buckets, int turn, int pigs){
        if(turn==1){
            return buckets<=2*pigs-1;
        }
        return possible(buckets/(2*pigs-1)+(buckets%(2*pigs-1)>0), turn-1, pigs);
    }
};

//1000, 2^4=16, 1000/16=62.5~63
//63, 2^3=8, 63/8~8
//8, 2^2=4, 8/4=2
//2, 1^2=2, 2/2=1




int main(){
    return 0;
}

