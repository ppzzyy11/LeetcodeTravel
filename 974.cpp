/*
 * 974.cpp
 * Copyright (C) 2021-04-30 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res=0;
        //all prefix subarries sum before i
        vector<int> cnt(K, 0);//MOD K, times
        cnt[0]=1;
        int sum=0;
        for(int i=0; i<A.size(); i++){
            sum=(sum+A[i]%K+K+K)%K;
            res+=cnt[sum];
            cnt[sum]++;
        }
        return res;
    }
};

class SolutionTLNK {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res=0;
        //all prefix subarries end at i, less contents but need transactions
        vector<int> cnt(K, 0);//MOD K, times
        for(int i=0; i<A.size(); i++){
            A[i]%=K;
            vector<int> pre=cnt;
            // cnt.resize(K,0);
            for(int j=0; j<K; j++){
                cnt[(j+A[i]+K)%K]=pre[j];
            }
            cnt[(A[i]+K)%K]++;
            res+=cnt[0];
        }
        return res;
    }
};





int main(){
    return 0;
}

