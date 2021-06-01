/*
 * 351.cpp
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
    vector<unordered_set<string>> rec;
public:
    int numberOfPatterns(int m, int n) {
        string path="";
        rec.resize(10, unordered_set<string>{});
        vector<bool> visited(10, false);
        backtracking(path, visited, m, n);
        int sum=0;
        for(int i=m; i<=n; i++){
            sum+=rec[i].size();
        }
        return sum;
    }

    void backtracking(string& path, vector<bool>& visited, int m, int n){
        if(path.size()==n){
            return ;
        }

        for(int i=1; i<=9; i++){
            if(visited[i]==true){
                continue;
            }
            path.push_back(i+'0');
            visited[i]=true;
            if(valid(path, visited))
            {
                if(path.size()>=m&&path.size()<=n)
                rec[(int)path.size()].insert(path);
                backtracking(path, visited,m, n);
            }
            visited[i]=false;
            path.pop_back();
        }



    }

    bool valid(const string& path, const vector<bool>& visited){
        vector<int> cnt(10, 0);
        //no duplicates
        for(const char& ch: path){
            cnt[ch-'1']++;
            if(cnt[ch-'1']>1){
                return false;
            }
        }


        //no jump
        for(int i=1; i<path.size(); i++){
            if(dangerous(path[i-1])&&dangerous(path[i])){
                int idx=getMiddle(path[i-1], path[i]);
                if(visited[idx]==true){
                    continue;
                }else{
                    return false;
                }
            }

            if(dangerous2(path[i-1])&&dangerous2(path[i])){
                int idx=getMiddle(path[i-1], path[i]);
                if(visited[idx]==true){
                    continue;
                }else{
                    return false;
                }
            }
            if(dangerous3(path[i-1])&&dangerous3(path[i])){
                int idx=getMiddle(path[i-1], path[i]);
                if(visited[idx]==true){
                    continue;
                }else{
                    return false;
                }
            }
        }


        return true;
    }

    bool dangerous(char ch){
        return ch=='1'||ch=='3'||ch=='7'||ch=='9';
    }

    int getMiddle(char ch1, char ch2){
        return (ch1+ch2)/2-'0';
    }

    bool dangerous2(char ch){
        return ch=='2'||ch=='8';
    }

    bool dangerous3(char ch){
        return ch=='4'||ch=='6';
    }
};





int main(){
    return 0;
}

