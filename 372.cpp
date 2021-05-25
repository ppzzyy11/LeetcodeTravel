/*
 * 372.cpp
 * Copyright (C) 2021-05-24 pzy <pzy@pzy-B250M-Wind>
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
    const int MOD=1337;
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        a=a%MOD;
        for(int i=b.size()-1; i>=0; i--){
            int p=b[i];
            res=(res*pow(a, p))%MOD;
            a=pow(a, 10)%MOD;

        }
        return res;
    }

    int pow(int x, int n){
        int res=1;
        while(n>0){
            if(n&1)
                res=res*x%MOD;
            n=(n>>1);
            x=x*x%MOD;
        }
        return res;
    }
};


class SolutionDirect {
    const int MOD=1337;
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        a%=MOD;
        while(1){
            if(get(b)){
                res*=a;
                res%=MOD;
            }
            a=(a*a)%MOD;
            if(divideBy2(b)){
                continue;
            }else{
                break;
            }
        }
        return res;
    }

    int divideBy2(vector<int>& b){
        int add=0;
        bool notZero=0;
        for(int i=0; i<b.size(); i++){
            int num=b[i];
            if(add){
                num+=10*add;
            }
            if(num!=0){
                notZero=1;
            }
            b[i]=num/2;
            add=num%2;
        }
        return notZero;
    }

    bool get(const vector<int>& b){
        int back=b.back();
        return back&1;
    }
};





int main(){
    return 0;
}

