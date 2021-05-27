/*
 * 488.cpp
 * Copyright (C) 2021-05-27 pzy <pzy@pzy-B250M-Wind>
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

    unordered_map<char, size_t> ch2idx{
        {'R', 0},
            {'Y', 1},
            {'B', 2},
            {'G', 3},
            {'W', 4}
    };
    unordered_map<string, unordered_map<string, int>> rec;
public:
    int findMinStep(string board, string hand) {
        int res=dfs(board, hand);
        return res>5?-1:res;
    }

    int dfs(string board, string hand){
        if(rec.count(board)!=0){
            if(rec[board].count(hand)!=0){
                return rec[board][hand];
            }
        }
        if(board.size()==0){
            return 0;
        }
        if(hand.size()==0){
            if(board.size()==0){
                return 0;
            }
            return 10000;
        }

        int res=10000;
        for(int m=0; m<=board.size(); m++){
            for(int j=0; j<hand.size(); j++){
            res=min(res, dfs(remove(board.substr(0, m)+hand[j]+board.substr(m)), hand.substr(0, j-0)+hand.substr(j+1))+1);
            }
        }
         //if(res<=5){
             //cout<<"board: "<<board<<"\n"<<"hand: "<<hand<<"\n"<<res<<endl;
         //}
        return rec[board][hand]=res;

    }

    string remove(string board){
        string res="";
        int s=0;
        int e=0;
        int cnt=0;
        while(s<board.size()){
            e=s;
            cnt=0;
            while(e<board.size()&&board[e]==board[s]){
                e++;
                cnt++;
            }
            if(cnt>=3){
                ;
            }else{
                res+=board.substr(s, e-s);
            }
            s=e;
        }
        if(board!=res){
            return remove(res);
        }
        return res;
    }


};





int main(){
    Solution s;
    cout<<s.findMinStep("RBYYBBRRB","YRBGB")<<endl;


    return 0;
}

