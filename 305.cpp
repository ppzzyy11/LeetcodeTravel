/*
 * 305.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 * Description:
 *
 *      To implement:
 *      How:
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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;



class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int part;

    UnionFind(int n)
    {
        this->n = n;
        part = n;
        parent.resize(n);
        for(int x = 0; x < n; x++)
            parent[x] = x;
        size.resize(n, 1);
    }

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return Find(parent[x]);
    }

    bool Union(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y)
            return false;
        if (size[root_x] > size[root_y])
            swap(root_x, root_y);
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
        part -= 1;
        return true;
    }

    bool in_the_same_part(int x, int y)
    {
        return Find(x) == Find(y);
    }

    int get_the_part_size(int x)
    {
        int root_x = Find(x);
        return size[root_x];
    }

};

class Solution {
    int MOD;
    unordered_set<int> rec;
    vector<vector<int>> dirs={
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind un(m*n);
        MOD=n;
        vector<int> res;
        int cnt=0;
        for(int i=0; i<positions.size(); i++){
            int x=positions[i][0];
            int y=positions[i][1];

            int idx=xy2idx(x, y);
            if(!rec.count(idx)){


                rec.insert(idx);
                cnt++;
                for(const vector<int>& dir: dirs){
                    int dx=dir[0];
                    int dy=dir[1];
                    if(x+dx>=0&&x+dx<m&&y+dy>=0&&y+dy<n){
                        int didx=xy2idx(x+dx, y+dy);
                        if(rec.count(didx)){
                            un.Union(idx, didx);
                        }
                    }
                }
            }
            res.push_back(cnt+un.part-m*n);

        }
        return res;
    }

    int xy2idx(int x, int y){
        return x*MOD+y;
    }

    pair<int, int> idx2xy(int idx){
        return {idx/MOD, idx%MOD};
    }
};





int main(){
    return 0;
}

