/*
 * 499.cpp
 * Copyright (C) 2021-05-27 pzy <pzy@pzy-B250M-Wind>
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



// DFS (924ms)
class Solution_dfs {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        M = maze.size();
        N = maze[0].size();
        vector<vector<int>> dists(M, vector<int>(N, numeric_limits<int>::max()));
        unordered_map<int, string> mp;
        dists[ball[0]][ball[1]] = 0;
        dfs(maze, ball[0], ball[1], hole, dists, mp);
        string res = mp[N * hole[0] + hole[1]];
        return res.empty() ? "impossible" : res;
    }


private:
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<char> way{'l', 'u', 'r', 'd'};
        int M;
        int N;

    void dfs(vector<vector<int>>& maze, int i, int j, vector<int>& hole,
             vector<vector<int>>& dists, unordered_map<int, string>& mp) {
        if (i == hole[0] && j == hole[1]) {
            return;
        }

        for (int k = 0; k < 4; k++) {
            int x = i;
            int y = j;
            int dist = dists[x][y];
            string path = mp[N * x + y];
            while (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 0 && (x != hole[0] || y != hole[1])) {
                x += dirs[k][0];
                y += dirs[k][1];
                dist++;
            }
            // backtrack one step from obstruction
            if (x != hole[0] || y != hole[1]) {
                x -= dirs[k][0];
                y -= dirs[k][1];
                dist--;
            }
            path.push_back(way[k]);
            if (dist < dists[x][y]) {
                dists[x][y] = dist;
                mp[N * x + y] = path;
                if (x != hole[0] || y != hole[1]) { // optional condition, pruning
                    dfs(maze, x, y, hole, dists, mp);
                }
            } else if (dist == dists[x][y] && mp[N * x + y].compare(path) > 0) {
                mp[N * x + y] = path;
                if (x != hole[0] || y != hole[1]) {
                    dfs(maze, x, y, hole, dists, mp);
                }
            }
        }
    }
};

// BFS (24ms)
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        M = maze.size();
        N = maze[0].size();
        vector<vector<int>> dists(M, vector<int>(N, numeric_limits<int>::max()));
        unordered_map<int, string> mp;
        dists[ball[0]][ball[1]] = 0;
        bfs(maze, ball[0], ball[1], hole, dists, mp);
        string res = mp[N * hole[0] + hole[1]];
        return res.empty() ? "impossible" : res;
    }


private:
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<char> way{'l', 'u', 'r', 'd'};
        int M;
        int N;

    void bfs(vector<vector<int>>& maze, int bx, int by, vector<int>& hole,
             vector<vector<int>>& dists, unordered_map<int, string>& mp) {
        if (bx == hole[0] && by == hole[1]) {
            return;
        }

        queue<vector<int>> q;
        q.push({bx, by});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front(); q.pop();
                auto i = cur[0];
                auto j = cur[1];
                for (int k = 0; k < 4; k++) {
                    int x = i;
                    int y = j;
                    int dist = dists[x][y];
                    string path = mp[N * x + y];
                    while (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 0 && (x != hole[0] || y != hole[1])) {
                        x += dirs[k][0];
                        y += dirs[k][1];
                        dist++;
                    }
                    // backtrack one step from obstruction
                    if (x != hole[0] || y != hole[1]) {
                        x -= dirs[k][0];
                        y -= dirs[k][1];
                        dist--;
                    }
                    path.push_back(way[k]);
                    if (dist < dists[x][y]) {
                        dists[x][y] = dist;
                        mp[N * x + y] = path;
                        if (x != hole[0] || y != hole[1]) { // optional condition, pruning
                            q.push({x, y});
                        }
                    } else if (dist == dists[x][y] && mp[N * x + y].compare(path) > 0) {
                        mp[N * x + y] = path;
                        if (x != hole[0] || y != hole[1]) {
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
};




int main(){
    return 0;
}

