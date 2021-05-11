/*
 * 787.cpp
 * Copyright (C) 2021-05-11 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        //prices
        vector<int> pre(n, INT_MAX);
        vector<int> cur(n, INT_MAX);
        cur[src]=0;
        while(k-->=0){
            pre=cur;

            for(const auto& flight: flights){
                int s=flight[0];
                int d=flight[1];
                int p=flight[2];
                if(pre[s]!=INT_MAX){
                    if(cur[d]==INT_MAX||pre[s]+p<cur[d]){
                        cur[d]=pre[s]+p;
                    }
                }
            }

        }

        return cur[dst]==INT_MAX?-1:cur[dst];

    }
};





int main(){
    return 0;
}

