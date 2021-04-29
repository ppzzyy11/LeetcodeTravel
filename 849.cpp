/*
 * 849.cpp
 * Copyright (C) 2021-04-29 pzy <pzy@pzy-B250M-Wind>
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
    int maxDistToClosest(vector<int>& seats) {
        int res=0;
        int pre=-1;
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==1){
                if(pre==-1&&i!=0){
                    res=i;
                }else {
                    res=max(res, (i-pre)/2);
                }
                pre=i;
            }
        }
        res=max(res,(int)seats.size()-pre-1);
        return res;
    }
};





int main(){
    return 0;
}

