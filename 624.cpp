/*
 * 624.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
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
    int maxDistance(vector<vector<int>>& arrays) {
        int res=INT_MIN;
        int minV=INT_MAX, maxV=INT_MAX;
        for(int i=0; i<arrays.size(); i++){
            vector<int>& array = arrays[i];
            if(i==0){
                minV=array[0];
                maxV=array.back();
            }else{
                res=max(res, array.back()-minV);
                res=max(res, maxV-array[0]);
                minV=min(minV, array[0]);
                maxV=max(maxV, array.back());
            }
        }


        return res;
    }
};





int main(){
    return 0;
}

