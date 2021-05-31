/*
 * 475.cpp
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int res=0;
        for(const int& house: houses){
            int l=0, r=heaters.size()-1;
            while(l+1<r){
                int m=(l+r)/2;

                if(heaters[m]>house){
                    r=m;
                }else if(heaters[m]<house){
                    l=m;
                }else{
                    res=max(res, 0);
                    l=r=m;
                    break;
                }
            }

            res=max(res, min(abs(heaters[r]-house), abs(heaters[l]-house)));
        }

        return res;

    }
};





int main(){
    return 0;
}

