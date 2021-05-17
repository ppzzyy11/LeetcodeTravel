/*
 * 12.cpp
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
    string intToRoman(int num) {
        int cnt=0;
        int n=10;
        string res="";
        while(num){
            res=num2Roman(num%n,cnt)+res;
            cnt++;
            num=num/10;
        }
        return res;

    }

    //input num is num*( 10^n )
    string num2Roman(int num, int n){
        string res="";
        char ch1, ch5,ch10;
        if(n==0){
            ch1='I';
            ch5='V';
            ch10='X';
        }else if(n==1){
            ch1='X';
            ch5='L';
            ch10='C';
        }else if(n==2){
            ch1='C';
            ch5='D';
            ch10='M';
        }else if(n==3){
            ch1='M';
        }

        if(num<=3){
            for(int i=0; i<num; i++){
                res=res+ch1;
            }
        }else if(num==4){
            res=res+ch1+ch5;
        }else if(num>=5&&num<=8){
            res=ch5;
            for(int i=6; i<=num; i++){
                res=res+ch1;
            }
        }else if(num==9){
            res=res+ch1+ch10;
        }else{
            res=ch10;
        }

        return res;
    }
};





int main(){
    return 0;
}

