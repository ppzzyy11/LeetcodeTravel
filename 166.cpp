/*
 * 166.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    string fractionToDecimal(int numerator, int denominator) {
        unsigned long a = (abs((long)numerator));
        unsigned long b = (abs((long)denominator));

        bool neg=false;
        if(numerator<0){
            neg=!neg;
        }
        if(denominator<0){
            neg=!neg;
        }
        string inte="";
        if(neg){
            inte+='-';
        }

        inte+=to_string(a/b);
        a=a%b;
        vector<int> f;
        vector<int> m;
        string fra="";
        bool rep=false;
        int s=-1,e=-1;
        while(a!=0){
            a=a*10;
            int i=0;
            for(;i<m.size(); i++){
                if(m[i]==a%b){
                    s=i+1;
                    e=f.size();
                    rep=true;
                    break;
                }
            }

            if(rep&&i<m.size()&&m[i]==a%b){
                f.push_back(a/b);
                m.push_back(a%b);
                break;
            }
            f.push_back(a/b);
            m.push_back(a%b);
            a=a%b;
        }
        if(s==-1){
            e=s=f.size();
        }

        for(int i=0; i<f.size()&&i<s; i++){
            fra+=(char)(f[i]+'0');
        }
        if(rep){
            fra+='(';
            for(int i=s; i<f.size()&&i<=e; i++){
                fra+=to_string(f[i]);
            }
            fra+=')';
        }
        string res;
        if(inte.size()!=0){
            res+=inte;
        }
        if(fra.size()!=0){
            res+='.';
            res+=fra;
        }

        return res=="-0"?"0":res;

    }


};





int main(){
    return 0;
}

