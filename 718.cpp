/*
 * 718.cpp
 * Copyright (C) 2021-04-26 pzy <pzy@pzy-B250M-Wind>
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




//class SolutionHash {
    //bool check(const vector<int>&nums1 , const vector<int>& nums2, int mid){
        ////

    //}
//public:
    //int findLength(vector<int>& nums1, vector<int>& nums2) {
        //int l=0, r=min(nums1.size(), nums2.size());
        //while(l+1<r){
            //int m = (r-l)/2+l;
            //if(check(nums1, nums2, m)){

            //}

        //}
    //}
//};



class SolutionAglin {
    int maxLen(const vector<int>& nums1, const vector<int>& nums2, int i, int j){
        int res=0;
        int k=0;
        int len=0;

        while(i+k<nums1.size()&&j+k<nums2.size()){
            if(nums1[i+k]==nums2[j+k]){
                len++;
            }else{
                len=0;
            }
            res=max(res, len);
            k++;
        }
        return res;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        for(int i=0; i<nums1.size(); i++){
            res=max(res, maxLen(nums1, nums2, i, 0));
        }
        for(int j=0; j<nums2.size(); j++){
            res=max(res, maxLen(nums1, nums2, 0, j));
        }
        return res;

    }
};


class SolutionDP {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int res=0;
        for(int i=1; i<=nums1.size(); i++){
            for(int j=1; j<=nums2.size(); j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
                }
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};


class SolutionBruteForce {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res= 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int cnt=0;
                for(int k=0; k+i<nums1.size()&&k+j<nums2.size(); k++ ){
                    if(nums1[i+k]==nums2[j+k]){
                        cnt++;
                        res=max(cnt, res);
                    }else{
                        break;
                    }


                }
            }
        }

        return res;
    }
};





int main(){
    return 0;
}

