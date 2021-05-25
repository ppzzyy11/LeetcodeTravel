/*
 * 255.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
public:
    bool verifyPreorder(vector<int>& preorder) {
        return recur(preorder, 0, preorder.size()-1,INT_MIN, INT_MAX );
    }

    bool recur(const vector<int>& preorder, int s, int e, int minV, int maxV){
        if(minV>maxV){
            return false;
        }
        if(s>e){
            return true;
        }
        for(int i=s; i<=e; i++){
            if(preorder[i]>maxV||preorder[i]<minV){
                return false;
            }
        }

        int m=s+1;
        while(m<=e){
            if(preorder[m]>preorder[s]){
                break;
            }
        }
        for(int i=m; i<=e; i++){
            if(preorder[i]<=preorder[s]){
                return false;
            }
        }



        bool res=1;

        res=recur(preorder, s+1, m-1, minV, min(maxV, preorder[s]));
        res&=recur(preorder, m, e, max(minV, preorder[s]), maxV);

        return res;
    }

};





int main(){
    return 0;
}

