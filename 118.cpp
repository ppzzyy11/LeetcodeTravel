/*
 * 118.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
 *
 */

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct TreeNode;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> tmp(1,1);
        res.push_back(tmp);
        for(int i=1; i<numRows; i++){
            tmp.resize(res.back().size()+1,1);
            for(int j=1; j<tmp.size()-1; j++){
                tmp[j]=res.back()[j]+res.back()[j-1];
            }
            res.push_back(tmp);
        }
        return res;
    }
};





int main(){
    return 0;
}

