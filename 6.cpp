/*
 * 6.cpp
 * Copyright (C) 2021-05-17 pzy <pzy@pzy-B250M-Wind>
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
public:
    string convert(string s, int numRows) {
        int n=numRows;
        int len=s.size();
        if(n==1){
            return s;
        }
        int h_idx=0;
        int t_idx=2*n-3;
        string res="";
        res=getRes(s, h_idx, 2*n-2);
        h_idx++;
        while(h_idx!=t_idx){
            res+=getRes(s, h_idx,t_idx, 2*n-2);
            h_idx++;
            t_idx--;
        }
        res+=getRes(s, h_idx, 2*n-2);

        return res;
    }

    string getRes(const string&str, int idx, int didx){
        string res="";
        while(idx>=0&&idx<str.size()){
            res+=str[idx];
            idx+=didx;
        }
        return res;
    }


    string getRes(const string&str, int idx1, int idx2, int didx){
        string res="";
        while(idx1>=0&&idx1<str.size()){
            res+=str[idx1];
            idx1+=didx;
            if(idx2>=0&&idx2<str.size()){
                res+=str[idx2];
            }
            idx2+=didx;
        }
        return res;
    }

};





int main(){
    return 0;
}

