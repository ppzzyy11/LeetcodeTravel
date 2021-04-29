/*
 * 873.cpp
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


//try to solve the problem with an array, which does not take the prefix into consideration.
//less space complexity
class SolutionMapDP {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_set<int> S(A.begin(), A.end());

        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};

class SolutionMatrixDP {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //arr[i][j]=
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(),0));
        //val 2 idx
        unordered_map<int, int> rec;

        //record
        for(int i=0; i<arr.size(); i++){
            rec[arr[i]]=i;
        }


        int res=0;
        for(int k=0; k<arr.size(); k++){
            for(int j=0; j<k; j++){
                if(arr[k]-arr[j]<arr[j]&&rec.count(arr[k]-arr[j])){
                    int i=rec[arr[k]-arr[j]];
                    //arr[i] + arr[j] = arr[k]
                    dp[j][k]=dp[i][j]+1;
                    res=max(res, dp[j][k]+2);
                }
            }
        }

        return res>=3?res:0;
    }
};





int main(){
    return 0;
}

