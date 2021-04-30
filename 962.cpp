/*
 * 962.cpp
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

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

//BFS
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        queue<pair<int, int> > que;
        unordered_set<pair<int, int>, pair_hash> rec;
        rec.insert(make_pair(0, A.size()-1));
        que.push(make_pair(0, A.size()-1));

        while(que.size()!=0){
            pair<int, int> front = que.front();
            que.pop();
            int l = front.first;
            int r = front.second;
            if(A[l]>A[r]){
                return r-l;
            }
            if(l+1!=r){
                pair<int,int> ll = make_pair(l+1, r);
                pair<int,int> rr = make_pair(l, r-1);
                if(rec.find(ll)!=rec.end()){
                    rec.insert(ll);
                    que.push(ll);
                }
                if(rec.find(rr)!=rec.end()){
                    rec.insert(rr);
                    que.push(rr);
                }
            }
        }
        return -1;
    }
};





int main(){
    return 0;
}

