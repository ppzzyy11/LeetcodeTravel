/*
 * 782.cpp
 * Copyright (C) 2021-05-03 pzy <pzy@pzy-B250M-Wind>
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
    int movesToChessboard(vector<vector<int>>& board) {
        if(verifyChess(board)){
            vector<int> column = getTwoByCloumn(board);
            vector<int> row = getTwoByRows(board);
            if(verify(column[0], column[1])&&verify(row[0], row[1])){
                return getShortestPath(max(column[0],column[1]),board.size())+getShortestPath(max(row[0],row[1]), board.size());
            }
        }
        return -1;

    }

    bool verifyChess(const vector<vector<int>>& board){
        set<int> rec;
        for(int i=0; i<board.size(); i++){
            int num=0;
            for(int j=0;j<board[i].size(); j++){
                num=(num<<1)+board[i][j];
            }
            rec.insert(num);
        }
        if(rec.size()!=2){
            return false;
        }

        rec.clear();
        for(int j=0; j<board[0].size(); j++){
            int num=0;
            for(int i=0; i<board.size(); i++){
                num=(num<<1)+board[i][j];
            }
            rec.insert(num);
        }
        if(rec.size()!=2){
            return false;
        }
        return true;
    }


    vector<int> getTwoByCloumn(const vector<vector<int>>& board){
        set<int> rec;
        for(int i=0; i<board.size(); i++){
            int num=0;
            for(int j=0;j<board[i].size(); j++){
                num=(num<<1)+board[i][j];
            }
            rec.insert(num);
        }
        vector<int> res;
        if(rec.size()!=2){
            return res;
        }
        for(auto it =rec.begin(); it!=rec.end(); it++){
            res.push_back(*it);
        }
        return res;
    }

    vector<int> getTwoByRows(const vector<vector<int>>& board){
        set<int> rec;
        for(int j=0; j<board[0].size(); j++){
            int num=0;
            for(int i=0;i<board.size(); i++){
                num=(num<<1)+board[i][j];
            }
            rec.insert(num);
        }
        vector<int> res;
        if(rec.size()!=2){
            return res;
        }
        for(auto it =rec.begin(); it!=rec.end(); it++){
            res.push_back(*it);
        }
        return res;
    }

    bool verify(int a, int b){
        int cnta=0;
        int cntb=0;
        while(a||b){
            if((a&1)==(b&1)){
                return false;
            }
            if(a&1) cnta++;
            if(b&1) cntb++;
            a=a>>1;
            b=b>>1;
        }
        return abs(cnta-cntb)<=1;
    }

    //minimal path to 101010 or 010101
    int getShortestPath(int a, int N){
        int n = getNumOf1(a);
        vector<int> nums = generateN(n, N);
        return min(getDistance(nums[0], a), getDistance(nums[1], a))/2;
    }

    int getNumOf1(int n){
        int res=0;
        while(n){
            res+=n&1;
            n=n>>1;
        }
        return res;
    }

    //n is the number of 1
    vector<int> generateN(int n, int N){
        vector<int> res;
        int k=N/2;
        int tmp=n;
        int num=0;
        if(N%2==1){
            //N=2*k+1
            while(n){
                num=(num<<2)+1;
                n--;
            }
            n=tmp;
            if(n==k){
                num=num<<1;
            }else{

            }
            res.push_back(num);
            res.push_back(num);
        }else{
            while(n){
                num=(num<<2)+1;
                n--;
            }
            n=tmp;
            res.push_back(num);
            num=num<<1;
            res.push_back(num);

        }

        return res;
    }

    int getDistance(int a, int b){
        int res=0;
        while(a||b){
            res+=((a&1)!=(b&1));
            a=a>>1;
            b=b>>1;
        }
        return res;
    }
};





int main(){
    Solution * so  = new Solution();
    vector<int> nums = so->generateN(1, 3);
    for(auto num: nums){
        cout<<num<<'\t';
    }
    cout<<endl;
    delete so;
    return 0;
}

