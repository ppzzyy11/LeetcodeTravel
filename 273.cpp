/*
 * 273.cpp
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
    unordered_map<int, string> num2str{
        {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"}
    };
public:
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        queue<string> que;
        string billion = num2StringBelow1000(num/1000000000, "Billion");
        if(billion.size()!=0)
            que.push(billion);
        string million = num2StringBelow1000(num%1000000000/1000000, "Million");
        if(million.size()!=0)
            que.push(million);
        string thousand = num2StringBelow1000(num%1000000/1000, "Thousand");
        if(thousand.size()!=0)
            que.push(thousand);
        string one = num2StringBelow1000(num%1000, "");
        if(one.size()!=0)
            que.push(one);
        string res="";
        while(que.size()!=0){
            res+=que.front();
            que.pop();
            if(que.size()!=0){
                res+=' ';
            }
        }

        return res;
    }


    string num2StringBelow1000(int num, string prefix){
        string str="";
        num=num%1000;
        if(num==0){
            return "";
        }
        if(num>=100)
            str+=num2str[num/100]+" "+"Hundred";
        num=num%100;
        if(num!=0&&str.size()!=0){
            str+=' ';
        }
        if(num<20){
            str+=num2str[num]+"";
        }else{
            str+=num2str[num/10*10];
            if(num%10!=0)
                str+=" "+num2str[num%10];
        }

        return str+(prefix.size()==0?"":' '+prefix);
    }

};





int main(){
    return 0;
}

