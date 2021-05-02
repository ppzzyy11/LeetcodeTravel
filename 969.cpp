/*
 * 969.cpp
 * Copyright (C) 2021-04-30 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> path;
        //every time flip the number to its back
        for(int num=arr.size(); num>=1; num--){
            reverseNumToBack(arr, num, path);
        }
        return path;
    }

    void reverseNumToBack(vector<int>& arr, int n, vector<int>& path){
        int idx=0;
        while(idx<arr.size()&&arr[idx]!=n){
            idx++;
        }
        if(idx==n-1){
            return;
        }
        reverse(arr.begin(), arr.begin()+idx+1);
        path.push_back(idx+1);
        reverse(arr.begin(), arr.begin()+n);
        path.push_back(n);
    }

};





int main(){
    return 0;
}

