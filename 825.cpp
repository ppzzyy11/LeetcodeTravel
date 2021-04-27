/*
 * 825.cpp
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
    int numFriendRequests(vector<int>& ages) {
        int res=0;
        vector<int> cnt(121,0);
        for(int i=0; i<ages.size(); i++){
            cnt[ages[i]]++;
        }

        for(int i=1; i<=120; i++){
            for(int j=1; j<=120; j++){
                //i request j
                if(j<=0.5*i+7|| j>i || (j>100&&i<100))
                    continue;
                res+=cnt[i]*cnt[j]-(i==j?cnt[i]:0);
            }
        }
        return res;
    }
};





int main(){
    return 0;
}

