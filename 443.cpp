/*
 * 443.cpp
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
    int compress(vector<char>& chars) {
        int i2w=0;
        int i2r=1;
        char ch=chars[0];
        int cnt=1;
        while(i2r<chars.size()){
            while(i2r>0&&i2r<chars.size()&&chars[i2r]==chars[i2r-1]){
                i2r++;
                cnt++;
            }
            //[i, i2r-1]

            //begin to write
            chars[i2w++]=ch;
            if(cnt>1){
                string num=num2str(cnt);
                for(int i=0; i<num.size(); i++){
                    chars[i2w++]=num[i];
                }
            }

            if(i2r<chars.size()){
                ch=chars[i2r];
                cnt=1;
                i2r++;
            }else{
                cnt=0;
            }
        }
        if(cnt==1){
            chars[i2w++]=ch;
        }


        return i2w;

    }

    string num2str(int num){
        string res="";
        while(num){
            res=(char)(num%10+'0')+res;
            num=num/10;
        }
        return res;
    }
};





int main(){
    return 0;
}

