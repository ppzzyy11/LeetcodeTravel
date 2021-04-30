/*
 * 915.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int partitionDisjoint(vector<int>& A) {
        vector<int> left(A.size(),INT_MAX);
        vector<int> right(A.size(),INT_MAX);
        for(int i=0; i<A.size(); i++){
            if(i==0){
                left[i]=A[i];
                continue;
            }
            left[i]=max(left[i-1], A[i]);
        }

        for(int i=A.size()-1; i>=0; i--){
            if(i==A.size()-1){
                right[i]=A[i];
                continue;
            }
            right[i]=min(right[i+1], A[i]);
        }

        for(int i=1; i<A.size(); i++){
            if(left[i-1]<=right[i]){
                return i;
            }
        }
        return -1;
    }
};





int main(){
    return 0;
}

