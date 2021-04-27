/*
 * 768.cpp
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
        vector<int> sorted_arr=arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        int l=0,r=0;
        int maxV=INT_MIN, minV=INT_MAX;
        int res=0;
        while(r<arr.size()){
            minV=min(minV, arr[r]);
            maxV=max(maxV, arr[r]);
            r++;
            //[l,r)
            if(minV==sorted_arr[l]&&maxV==sorted_arr[r-1]&&check(arr,sorted_arr, l, r)){
                res++;
                minV=INT_MAX;
                maxV=INT_MIN;
                l=r;
            }

        }
        return res;
    }

    //[l,r)
    bool check(const vector<int>& arr, const vector<int>& sorted_arr, int l, int r){
        unordered_map<int, int> rec;
        for(int i=l; i<r; i++){
            rec[arr[i]]++;
            rec[sorted_arr[i]]--;
        }
        for(auto it =rec.begin(); it!=rec.end(); it++){
            if(it->second!=0){
                return false;
            }
        }

        return true;
    }
};





int main(){
    return 0;
}

