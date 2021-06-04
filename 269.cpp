/*
 * 269.cpp
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



class Solution {
    //0 for not visited, 1 for being visited, 2 for after visited
    vector<int> visited;
    vector<vector<bool>> edges;
    vector<char> res;
    vector<bool> tores;
    bool valid=true;
public:
    string alienOrder(vector<string>& words) {
        //generate edges from words
        edges.resize(26, vector<bool>(26, false));
        tores.resize(26, false);
        for(int i=1; i<words.size(); i++){
            generateEdge(words[i-1], words[i]);
        }

        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                tores[words[i][j]-'a']=true;
            }
        }

        //
        visited.resize(26, 0);
        for(int i=0; i<26; i++){
            if(tores[i]==true&&visited[i]==0) {
                dfs(i);
                if(valid==false){
                    break;
                }
            }
        }


        string str(res.rbegin(), res.rend());
        return valid?str:"";

    }


    void generateEdge(string smaller, string bigger){
        int len=min(bigger.size(), smaller.size());
        int i=0;
        for(; i<len; i++){
            if(bigger[i]!=smaller[i]){
                edges[smaller[i]-'a'][bigger[i]-'a']=true;
                break;
            }
        }
        if(i==len){
            valid = smaller.size()<=bigger.size();
        }
    }

    //dfs and detect cycle
    bool dfs(int i){
        if(i<0||i>=26){
            return false;
        }
        if(visited[i]==2){
            return false;
        }
        //being visited
        visited[i]=1;

        for(int j=0; j<26; j++){
            if(i==j){
                continue;
            }
            if(edges[i][j]==true){
                if(visited[j]==1){
                    valid=false;
                    return false;
                }
                dfs(j);
                if(valid==false){
                    return false;
                }
            }
        }

        visited[i]=2;
        res.push_back(i+'a');
        return true;
    }
};





int main(){
    return 0;
}

