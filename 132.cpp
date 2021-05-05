/*
 * 132.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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

//Pass
class SolutionDownUp {
public:
    int cnt=0;
    int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), true));
        //[i,j]
        for(int j=0; j<s.size(); j++){
            for(int i=j-1; i>=0; i--){
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                cnt++;
            }
        }

        vector<int> f(s.size(), INT_MAX);
        for(int i=0; i<s.size(); i++){
            if(dp[0][i]==true){
                f[i]=0;
            }else{
                for(int j=0; j<i; j++){
                    if(dp[j+1][i])
                      f[i]=min(f[i], f[j]+1);
                }
            }
        }
        return f.back();
    }
};

//Updown why TLE? O(N^3)???, because you did not calculate the palindreom matrix
class SolutionUpDown {
public:
    int cnt=0;
    int minCut(string s) {
        //INT_MAX means not memorised
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, INT_MAX));
        return miniCur(dp, s, 0, s.size()-1);
    }

    int miniCur(vector<vector<int>>& dp, const string& str, int s, int e){
        if(s>e||e>=str.size()||s<0){
            return INT_MAX;
        }
        if(dp[s][e]!=INT_MAX){
            return dp[s][e];
        }
        //cout<<s<<":"<<e<<endl;
        //cnt++;
        //O(N)
        if(isPalindrome(str, s, e)){
            return dp[s][e]=0;
        }
        cnt++;
        for(int m=s; m<e; m++){
            dp[s][e]=min(miniCur(dp, str, s, m)+miniCur(dp, str, m+1, e)+1, dp[s][e]);
        }
        return dp[s][e];
    }

    bool isPalindrome(const string& str, int s, int e){
        while(s<e){
            if(str[e--]!=str[s++]){
                return false;
            }
        }
        return true;
    }
};





int main(){
    string str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout<<"str.size()="<<str.size()<<endl;
    SolutionUpDown *ud= new SolutionUpDown();
    cout<<ud->minCut(str)<<endl;
    cout<<"ud cnt="<<ud->cnt<<endl;
    SolutionDownUp *du= new SolutionDownUp();
    cout<<du->minCut(str)<<endl;
    cout<<"du cnt="<<du->cnt<<endl;
    return 0;
}

