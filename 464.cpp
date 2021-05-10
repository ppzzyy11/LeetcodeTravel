/*
 * 464.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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

    //visited, des
    //unordered_map<int, unordered_map<int, bool> > rec;
    unordered_map<int, bool > rec;
    // vector<vector<int> > rec;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
        {
            return true;
        }
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal)
        {
            return false;
        }

        // rec.resize(addNth(0, maxChoosableInteger+), vector<int>(desiredTotal, -1));
        return recur(0, desiredTotal, maxChoosableInteger);
    }

    bool recur(int visited, int des, const int& maxChoosableInteger){
        // if(rec[visited][des]!=-1){
        //if(rec.count(visited)&&rec[visited].count(des)){
            //return rec[visited][des];
        //}

        if(rec.count(visited)){
            return rec[visited];
        }

        for(int i=1; i<=maxChoosableInteger; i++){
            if(getNthBit(visited, i)==false){
                if(i>=des||recur(addNth(visited, i), des-i, maxChoosableInteger)==false){
                    //return rec[visited][des]=true;
                    return rec[visited]=true;
                }
            }
        }

        return rec[visited]=false;
        //return rec[visited][des]=false;

    }

    inline bool getNthBit(int num, int n){
        return num&(1<<n);
    }

    inline int addNth(int num, int n){
        return num|(1<<n);
    }

    inline int removeNth(int num, int n){
        return num&~(1<<n);
    }

};





int main(){
    Solution s;
    cout<<s.removeNth(7,0);
    return 0;
}

