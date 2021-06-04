/*
 * 399.cpp
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
    unordered_map<string, unordered_map<string, double>> edges;
    int M;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        M=equations.size();
        for(int i=0 ;i<equations.size(); i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double v=values[i];
            edges[a][b]=v;
            if(equal(v, 0)){
                ;
            }else{
                edges[b][a]=1/v;
            }
        }

        vector<double> res;
        for(int i=0; i<queries.size(); i++){
            res.push_back(getRes(queries[i][0], queries[i][1]));
        }
        return res;
    }

    bool equal(double a, double b){
        return abs(a-b)<0.000001;
    }

    double getRes(string s, string d){
        unordered_map<string, double> res;
        res[s]=1.0;
        int i=M;
        while((i--)>0){
            unordered_map<string, double> tmp=res;
            for(auto it=res.begin(); it!=res.end(); it++){
                const string& node=it->first;
                double v=it->second;
                const unordered_map<string, double>& es=edges[node];
                for(auto it2=es.begin(); it2!=es.end(); it2++){
                    const string& node2=it2->first;
                    double v2=it2->second;
                    if(tmp.count(node2)==0||tmp[node2]>v*v2){
                        tmp[node2]=v*v2;
                    }
                }
            }
            res=tmp;
        }
        if(res.count(d)==0||edges[s].size()==0){
            return -1.0;
        }

        return res[d];

    }

};





int main(){
    return 0;
}

