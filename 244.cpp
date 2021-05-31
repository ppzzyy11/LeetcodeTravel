/*
 * 244.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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



class WordDistance {
    unordered_map<string, vector<int>> idx;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++){
            idx[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        if(word1==word2){
            return 0;
        }
        const vector<int>& idx1=idx[word1];
        const vector<int>& idx2=idx[word2];
        int i1=0, i2=0;
        int res=INT_MAX;
        while(i1<idx1.size()||i2<idx2.size()){
            if(i1<idx1.size()&&i2<idx2.size()){
                res=min(res, abs(idx1[i1]-idx2[i2]));
                if(idx1[i1]>idx2[i2]){
                    i2++;
                }else{
                    i1++;
                }
            }else if(i1==idx1.size()){
                res=min(res, abs(idx1[i1-1]-idx2[i2]));
                i2++;
            }else if(i2==idx2.size()){
                res=min(res, abs(idx2[i2-1]-idx1[i1]));
                i1++;
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

