/*
 * 978.cpp
 * Copyright (C) 2021-05-02 pzy <pzy@pzy-B250M-Wind>
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
    int maxTurbulenceSize(vector<int>& arr) {
        int pre_even, pre_odd;
        int even, odd;
        int res=1;
        int len=1;
        //first case
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                len=1;
            }
            if(i%2==1){
                if(arr[i]<arr[i-1]){
                    len++;
                }else{
                    len=1;
                }
            }else {//i%2==0
                if(arr[i]>arr[i-1]){
                    len++;
                }else{
                    len=1;
                }
            }
            res=max(res, len);
        }

        len=1;
        //first case
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                len=1;
            }
            if(i%2==0){
                if(arr[i]<arr[i-1]){
                    len++;
                }else{
                    len=1;
                }
            }else {//i%2==0
                if(arr[i]>arr[i-1]){
                    len++;
                }else{
                    len=1;
                }
            }
            res=max(res, len);
        }
        return res;
    }
};





int main(){
    return 0;
}

