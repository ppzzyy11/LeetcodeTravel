/*
 * 795.cpp
 * Copyright (C) 2021-04-27 pzy <pzy@pzy-B250M-Wind>
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
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R)- count(A, L-1);
    }

    //return number of subarresi that only contain numbers less than or equal to num
    int count(const vector<int>& A, int num){
        int res=0;
        int cnt=0;
        for(int i=0; i<A.size(); i++){
            if(A[i]<=num){
                cnt++;
            }else{
                res+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        res+=(cnt*(cnt+1))/2;
        return res;
    }
};





int main(){
    return 0;
}

