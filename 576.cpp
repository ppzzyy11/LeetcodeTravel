/*
 * 576.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};
const long MOD=1000000007;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0){
            return 0;
        }
        unordered_map<pair<long,long>,long, pair_hash > pre;
        unordered_map<pair<long,long>,long, pair_hash > cur;

        cur[make_pair(startRow, startColumn)]=1;

        long res=count(cur, m-1, n-1);
        while(maxMove>1){
            maxMove--;
            pre=cur;
            cur.clear();
            for(auto it=pre.begin(); it!=pre.end(); it++){
                long x=it->first.first;
                long y=it->first.second;
                insert(x, y, m-1, n-1, cur,(it->second)%MOD);
            }
            res+=count(cur, m-1, n-1)%MOD;
            res=res%MOD;
        }

        return res;

    }

    void insert(long x, long y,long maxX, long maxY,  unordered_map<pair<long,long>,long, pair_hash >& rec, long cnt){
        if(x-1>=0){
            rec[make_pair(x-1, y)]+=cnt;
        }
        if(x+1<=maxX){
            rec[make_pair(x+1, y)]+=cnt;
        }
        if(y-1>=0){
            rec[make_pair(x, y-1)]+=cnt;
        }
        if(y+1<=maxY){
            rec[make_pair(x, y+1)]+=cnt;
        }
    }

    long count(unordered_map<pair<long,long>,long,pair_hash >&rec, long maxX, long maxY){
        long res=0;
        for(auto it=rec.begin(); it!=rec.end(); it++){
            long x=it->first.first;
            long y=it->first.second;
            long cnt=it->second;
            res+=(x==0)*cnt;
            res+=(x==maxX)*cnt;
            res+=(y==0)*cnt;
            res+=(y==maxY)*cnt;
            res=res%MOD;
        }
        return res%MOD;
    }


};





int main(){
    return 0;
}

