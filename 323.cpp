/*
 * 323.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind s(n);
        for(const vector<int>& edge: edges){
            s.Union(edge[0], edge[1]);
        }
        return s.part;
    }
};





int main(){
    return 0;
}

