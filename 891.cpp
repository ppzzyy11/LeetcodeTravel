/*
 * 891.cpp
 * Copyright (C) 2021-04-29 pzy <pzy@pzy-B250M-Wind>
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



//TC O(N*lgN)
//https://leetcode-cn.com/problems/sum-of-subsequence-widths/solution/zi-xu-lie-kuan-du-zhi-he-by-leetcode/

//TLE O(N^2)
class SolutionN2 {
    long long MOD=1000000007;
    vector<long> rec;
    vector<long> tmp;
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        pow(A.size());
        cout<<A.size();
        long res=0;
        for(int i=0; i<A.size(); i++){
            for(int j=i+1; j<A.size(); j++){
                if(A[j]==A[i]){
                    continue;
                }
                tmp[j-i-1]+=A[j]-A[i];
            }
        }

        for(int i=0; i<tmp.size(); i++){
            if(tmp[i]!=0){
                res+=rec[i]*(long)(tmp[i]);
                res=res%MOD;
            }
        }
        return res;
    }
    void pow(int n){
        rec.resize(n, 0);
        tmp.resize(n, 0);
        long res=1;
        rec[0]=res;
        for(int i=1; i<n; i++){
            res*=2;
            res%=MOD;
            rec[i]=res;
        }
    }
};





int main(){
    return 0;
}

