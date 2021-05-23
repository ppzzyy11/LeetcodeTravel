/*
 * 65.cpp
 * Copyright (C) 2021-05-18 pzy <pzy@pzy-B250M-Wind>
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
    bool isNumber(string s) {
        int cntE=0;
        int cnte=0;
        for(char ch: s){
            if(ch=='e'){
                cnte++;
            }
            if(ch=='E'){
                cntE++;
            }
        }
        vector<string> nums;
        if(cntE>0&&cnte>0){
            return false;
        }
        if(cntE>1||cnte>1){
            return false;
        }

        if(cnte){
            nums=splitStrByChar(s, 'e');
        }else if(cntE){
            nums=splitStrByChar(s, 'E');
        }else{
            nums.push_back(s);
        }

        return (isDecimalNumber(nums[0])||isInteger(nums[0]))&&( nums.size()==2?isInteger(nums[1]):true);

    }


    bool isInteger(string s){
        int i=0;
        if(s[i]=='-'||s[i]=='+'){
            i++;
        }
        if(i==s.size()){
            return false;
        }
        while(i<s.size()){
            if(s[i]<'0'||s[i]>'9'){
                return false;
            }
            i++;
        }
        return true;

    }

    bool isDecimalNumber(string s){
        int i=0;
        if(s[i]=='+'||s[i]=='-'){
            i++;
        }
        if(i==s.size()){
            return false;
        }

        int dot=i;
        while(dot<s.size()&&s[dot]!='.'){
            dot++;
        }
        string pre=s.substr(i, dot-i);
        string suf=dot+1<s.size()?s.substr(dot+1):"";
        if(pre.size()==0&&suf.size()==0){
            return false;
        }
        for(char ch: pre){
            if(ch<'0'||ch>'9'){
                return false;
            }
        }
        for(char ch: suf){
            if(ch<'0'||ch>'9'){
                return false;
            }
        }
        return true;

    }
    vector<string> splitStrByChar(string s, char ch){
        vector<string> res;
        string tmp="";
        int i=0;
        while(i<s.size()){
            if(s[i]==ch){
                res.push_back(tmp);
                tmp="";
            }else{
                tmp+=s[i];
            }
            i++;
        }
        res.push_back(tmp);
        return res;
    }
};





int main(){
    return 0;
}

