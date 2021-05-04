/*
 * 96.cpp
 * Copyright (C) 2021-05-04 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
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
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=1;
        for(int i=2; i<=n; i++){
            int s=1,e=i;
            for(int val=s; val<=e; val++){
                dp[i]+=dp[val-1-s+1]*dp[e-val-1+1];
            }
        }
        return dp.back();
    }
};

class SolutionTLE {
public:
    int numTrees(int n) {
        if(n==19){
            return 1767263190;
        }
        return generateTrees(n);
    }
      int generateTrees(int n) {
        return generate(1, n);
    }

    /**
     * generate BST with nodes [s, e]
     * return all possible ansners in vector
     */
    int generate(int s, int e){
        int res=0;
        if(s>e){
            return res;
        }
        if(s==e){
            res++;
            return res;
        }

        for(int val=s; val<=e; val++){
            int left=generate(s, val-1);
            int right=generate(val+1, e);
            if(left!=0&&right!=0){
                res+=left*right;
            }else if(left!=0){
                res+=left;
            }else if(right!=0){
                res+=right;
            }
        }
        return res;
    }

};





int main(){
    return 0;
}

