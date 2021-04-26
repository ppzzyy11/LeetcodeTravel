/*
 * 769.cpp
 * Copyright (C) 2021-04-26 pzy <pzy@pzy-B250M-Wind>
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
    int maxChunksToSorted(vector<int>& arr) {
        int l=0, r=0;
        int minV=INT_MAX, maxV=INT_MIN;
        int res=0;
        while(r<arr.size()){
            minV=min(minV, arr[r]);
            maxV=max(maxV, arr[r]);
            r++;
            //[l,r)

            if(l==minV&&r-1==maxV){
                res++;
                l=r;
                minV=INT_MAX;
                maxV=INT_MIN;
            }
        }

        return res;

    }
};





int main(){
    return 0;
}

