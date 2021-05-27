/*
 * 207.cpp
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



class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid=true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const vector<int>& edge: prerequisites){
            edges[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(visited[i]==0){
                dfs(i);
            }
        }

        return valid;

    }

    void dfs(int s){
        visited[s]=1;
        for(const int& d: edges[s]){
            if(visited[d]==0){
                dfs(d);
                if(!valid){
                    return ;
                }
            }else if(visited[d]==1){
                valid=false;
                return ;
            }
        }
        visited[s]=2;
    }
};







int main(){
    return 0;
}

