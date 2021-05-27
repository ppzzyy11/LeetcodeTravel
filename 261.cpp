/*
 * 261.cpp
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
    vector<vector<int>> eds;
    vector<int> visited;
    //travel
    vector<int>result;
    //detect cycle
    bool valid=true;

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        eds.resize(n);
        visited.resize(n, 0);
        for(const vector<int>& edge:edges){
            eds[edge[0]].push_back(edge[1]);
            eds[edge[1]].push_back(edge[0]);
        }
        dfs(0, n);
        return valid&&result.size()==n;

    }


    void dfs(int s, int f){
        visited[s]=1;
        result.push_back(s);

        for(const int &d : eds[s]){
            if(d!=f){
                if(visited[d]==0){
                    dfs(d, s);
                    if(valid==false){
                        return ;
                    }
                }else {
                    valid=false;
                    return ;
                }
            }
        }



    }


};





int main(){
    return 0;
}

