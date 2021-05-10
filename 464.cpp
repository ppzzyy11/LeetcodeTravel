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
    unordered_map<int, unordered_map<int, bool> > rec;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return recur(0, desiredTotal, maxChoosableInteger);
    }

    bool recur(int visited, int des, const int& maxChoosableInteger){
        if(rec[visited].count(visited)&&rec[visited].count(des)){
            return rec[visited][des];
        }

        for(int i=maxChoosableInteger; i>=0; i--){
            if(getNthBit(visited, i)==false&&i>=des){
                return rec[addNth(visited, i)][des]=true;
            }
        }

        for(int i=1; i<=maxChoosableInteger; i++){
            if(getNthBit(visited, i)==false){
                addNth(visited, i);
                if(recur(visited, des-i, maxChoosableInteger)==false){
                    return rec[visited][des]=true;;
                }
                removeNth(visited, i);
            }
        }

        return rec[visited][des]=false;

    }

    bool getNthBit(int num, int n){
        return num&(1<<n);
    }

    int addNth(int num, int n){
        return num|(1<<n);
    }

    int removeNth(int num, int n){
        return num&~(1<<n);
    }

};





int main(){
    Solution s;
    cout<<s.removeNth(7,0);
    return 0;
}

