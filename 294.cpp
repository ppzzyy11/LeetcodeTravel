/*
 * 294.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    unordered_map<string, bool> rec;
public:
    bool canWin(string currentState) {
        return backtracking(currentState);
    }

    bool backtracking(string& currentState){
        if(rec.count(currentState)!=0){
            return rec[currentState];
        }

        for(int i=0; i<currentState.size()-1; i++){
            //ok
            if(currentState[i]=='+'&&currentState[i]==currentState[i+1]){
                flip(currentState,i);
                flip(currentState,i+1);
                bool ans=backtracking(currentState);
                flip(currentState,i);
                flip(currentState,i+1);
                if(ans==false){
                    return rec[currentState]=true;
                }
            }
        }

        return rec[currentState]=false;

    }

    void flip(string& str, int i){
        if(i<str.size()){
            if(str[i]=='-'){
                str[i]='+';
            }else{
                str[i]='-';
            }
        }
    }
};





int main(){
    return 0;
}

