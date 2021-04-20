/*
 * 495.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        int s=-1;
        int e=-1;
        for(int i=0; i<timeSeries.size(); i++){
            if(s==-1){
                s=timeSeries[i];
                e=timeSeries[i]+duration-1;
            }else if(timeSeries[i]<=e){
                e=timeSeries[i]+duration-1;
            }else{
                sum+=e-s+1;
                               s=timeSeries[i];
                e=timeSeries[i]+duration-1;
            }
        }
        if(s!=-1){
            sum+=e-s+1;
        }
        return sum;

    }
};





int main(){
    return 0;
}

