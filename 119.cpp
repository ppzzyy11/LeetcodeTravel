/*
 * 119.cpp
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
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1, 1);
        vector<int> pre;
        for(int i=0; i<rowIndex; i++){
            pre=cur;
            cur.resize(pre.size()+1,1);
            for(int j=1; j<cur.size()-1; j++){
                cur[j]=pre[j]+pre[j-1];
            }
        }
        return cur;
    }
};





int main(){
    return 0;
}

