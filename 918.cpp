/*
 * 918.cpp
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
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> left(A.size(), 0);
        vector<int> right(A.size(), 0);
        int tmp=0;
        for(int i=0; i<A.size(); i++){
            tmp+=A[i];
            left[i]=tmp;
        }

        tmp=0;
        for(int i=A.size()-1; i>=0; i--){
            tmp+=A[i];
            right[i]=tmp;
        }


    }
};





int main(){
    return 0;
}

