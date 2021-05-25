/*
 * 248.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    int strobogrammaticInRange(string low, string high) {
        return getNumByHigh(str2long(high))-getNumByHigh(str2long(low)-1);

    }

    long str2long(string str){
        long res=0;
        for(int i=0; i<str.size(); i++){
            res=res*10+str[i]-'0';
        }
        return res;
    }

    int getNumByHigh(long high){
        if(high<0){
            return 0;
        }
        if(high==0){
            return 1;
        }

        int len=getLen(high);
        int res=0;
        while(len-1>=0)
        {
            res+=getNumByLen(len-1);
            len--;
        }
        res+=recur(high, 0, 0, getLen(high)-1, getLen(high));

        return res;
    }

    long recur(const long high, long tmp, int s, int e, const int len){
        long res=0;
        if(tmp>high){
            return res;
        }
        if(s>e){
            return tmp<=high;
        }
        if(e!=len-1){
            res+=recur(high, tmp, s+1, e-1, len);
        }
        res+=recur(high, tmp+1*(pow(10,s)+(s==e?0:pow(10,e))), s+1, e-1, len );
        if(s!=e)
        res+=recur(high, tmp+6*pow(10,s)+9*(s==e?0:pow(10,e)), s+1, e-1, len );
        res+=recur(high, tmp+8*(pow(10,s)+(s==e?0:pow(10,e))), s+1, e-1, len );
        if(s!=e)
        res+=recur(high, tmp+9*pow(10,s)+6*(s==e?0:pow(10,e)), s+1, e-1, len );
        return res;
    }

    int getLen(long num){
        int len=0;
        while(num>0){
            len++;
            num=num/10;
        }
        return len;
    }


    int getNumByLen(int len){
        if(len==0){
            return 1;
        }
        if(len==1){
            return 2;
        }
        if(len%2==0){
            return pow(5, len/2)-pow(5, len/2-1);
        }
        return pow(5, len/2)*3-pow(5, len/2-1)*3;

    }

    long pow(long x, long n){
        long res=1;
        while(n>0){
            if(n&1)
            res=res*x;
            x=x*x;
            n=(n>>1);
        }
        return res;
    }
};





int main(){
    return 0;
}

