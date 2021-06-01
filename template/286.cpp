/*
 * 286.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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



class Solution {
    vector<pair<int, int>> dirs={
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        int n=rooms[0].size();

        vector<pair<int, int>> gates;
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[i].size(); j++){
                if(rooms[i][j]==0){
                    gates.push_back(make_pair(i,j));
                }
            }
        }

        for(int i=0; i<gates.size(); i++){
            queue<pair<int, int>> que;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[gates[i].first][gates[i].second]=true;
            que.push(gates[i]);
            int cnt=0;
            while(que.size()){
                int n=que.size();
                cnt++;
                while(n-->0){
                    pair<int, int> fnt=que.front();
                    que.pop();

                    for(pair<int, int> dir: dirs){
                        int x=fnt.first+dir.first;
                        int y=fnt.second+dir.second;
                        if(visited[x][y]==true){
                            continue;
                        }else{
                            visited[x][y]=true;

                            que.push(make_pair(x, y));

                            rooms[x][y]=min(rooms[x][y], cnt);
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

