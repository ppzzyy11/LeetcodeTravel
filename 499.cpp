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






struct pair_hash{
    template<class T1, class T2>
        std::size_t operator()(std::pair<T1, T2> const &pair) const{
            std::size_t h1=std::hash<T1>()(pair.first);
            std::size_t h2=std::hash<T2>()(pair.second);

            return h1^h2;
        }
};

class SolutionSPNotRight {

public:
    //shortest length in lexicographical order.
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        unordered_set<pair<int, int>, pair_hash> rec;
        pair<int, int> NIL=make_pair(-1, -1);
        queue<pair<int,int>> que;
        pair<int, int> start=make_pair(ball[0], ball[1]);
        que.push(start);
        que.push(NIL);
        rec.insert(start);
        pair<int, int> end=make_pair(hole[0], hole[1]);


        //record parent
        unordered_map<pair<int,int>, vector<pair<int, int>>, pair_hash> from;

        from[start]={};
        //every layer record
        unordered_map<pair<int,int>, vector<pair<int, int>>, pair_hash> layer;
        while(que.size()){
            pair<int, int> fnt=que.front();
            que.pop();
            if(equal(fnt, NIL)){
                if(que.size()){
                    que.push(NIL);
                }

                for(auto it=layer.begin(); it!=layer.end(); it++){
                    for(int i=0; i<it->second.size(); i++){
                        from[it->first].push_back(it->second[i]);
                    }
                }

                layer.clear();
                if(from.count(end)!=0){
                    break;
                }

            }else{
                pair<int, int> up=go(fnt, 1, 0, maze,end);
                if(!equal(fnt, up)&&from.count(up)==0){
                    layer[up].push_back(fnt);
                    que.push(up);
                }
                pair<int, int> down=go(fnt, -1, 0, maze,end);
                if(!equal(fnt, down)&&from.count(down)==0){
                    layer[down].push_back(fnt);
                    que.push(down);
                }
                pair<int, int> left=go(fnt, 0, -1, maze,end);
                if(!equal(fnt, left)&&from.count(left)==0){
                    layer[left].push_back(fnt);
                    que.push(left);
                }
                pair<int, int> right=go(fnt, 0, 1, maze,end);
                if(!equal(fnt, right)&&from.count(right)==0){
                    layer[right].push_back(fnt);
                    que.push(right);
                }
            }

        }

        for(auto it=from.begin(); it!=from.end(); it++){
            cout<<"to "<<it->first.first<<","<<it->first.second<<"\n";
            for(int i=0; i<it->second.size(); i++){
                cout<<"from "<<it->second[i].first<<","<<it->second[i].second<<"\n";
            }
        }
        //reconstruct paths
        //from start to end
        vector<string> res=reconstrcut(start, end, from);
        if(res.size()==0){
            return "impossible";
        }
        sort(res.begin(), res.end());
        //return possible results
        return res[0];
    }
    vector<string> reconstrcut(pair<int, int>& start, pair<int, int>& end, unordered_map<pair<int, int>, vector<pair<int, int>>, pair_hash>& from){
        vector<string> res;
        vector<vector<pair<int, int>>> paths;
        vector<pair<int, int>> path;
        dfs(paths, path, start, end, from);
        cout<<paths.size()<<endl;
        return paths2strs(paths);
    }

    vector<string> paths2strs(const vector<vector<pair<int, int>>>& paths){
        vector<string> strs;
        for(const vector<pair<int, int>>& path: paths){
            string str="";
            for(int i=0; i<path.size()-1; i++){
                char ch=getDirection(path[i+1], path[i]);
                str+=ch;
            }
            reverse(str.begin(), str.end());
            strs.push_back(str);
        }
        return strs;
    }

    char getDirection(const pair<int, int>& p1, const pair<int, int>& p2){
        if(p1.first==p2.first){
            return p1.second>p2.second?'l':'r';
        }

        if(p1.second==p2.second){
            return p1.first>p2.first?'u':'d';
        }
        return 'e';


    }

    //reconstruct paths
    void dfs(vector<vector<pair<int, int>>>& res, vector<pair<int, int>>& path, pair<int, int>& start, pair<int, int>& end,unordered_map<pair<int, int>, vector<pair<int, int>>, pair_hash>& from  ){
        for(int i=0; i<path.size(); i++){
            cout<<path[i].first<<","<<path[i].second<<'\t';
        }
        cout<<'\n';
        if(path.size()!=0&&equal(path.back(), start)){
            res.push_back(path);
            return ;
        }

        if(path.size()==0){
            path.push_back(end);
        }
            pair<int, int> to=path.back();
            const vector<pair<int, int> >& ps = from[to];
            for(int i=0; i<ps.size(); i++){
                pair<int, int> p =ps[i];
                path.push_back(p);
                dfs(res, path, start, end, from);
                path.pop_back();
            }


    }

    bool equal(pair<int, int>& p1, pair<int,int>& p2){
        return p1.first==p2.first&&p1.second==p2.second;
    }

    pair<int, int> go(pair<int, int> start, int dx, int dy, const vector<vector<int>>& maze, const pair<int, int>& hole){
        int x=start.first;
        int y=start.second;
        while(x+dx>=0&&x+dx<maze.size()&&y+dy>=0&&y+dy<maze[0].size()&&maze[x+dx][y+dy]!=1){
            x+=dx;
            y+=dy;
            if(x==hole.first&&y==hole.second){
                break;
            }
        }
        return make_pair(x, y);

    }
};


int main(){
    return 0;
}

