/*
 * 423.cpp
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
    unordered_map<int, string> int2str{
            {0, "zero"},//1 unique z
            {1, "one"},//left o
            {2, "two"},//2 unique w
            {3, "three"},//4 unique h
            {4, "four"},//5 unique u
            {5, "five"},//6 unique f
            {6, "six"},//7 unique x
            {7, "seven"},//8 unique s
            {8, "eight"},//3 unique t
            {9, "nine"}//9 unique i
    };
public:
    string originalDigits(string s) {
        vector<int> cnt(26, 0);
        for(char ch: s){
            cnt[ch-'a']++;
        }

        vector<int> rec(10, 0);
        vector<int> nums{0, 2, 8, 3, 4, 5, 6, 7, 9, 1};
        for(int num: nums){
            string str=int2str[num];
            int time=INT_MAX;
            for(char ch: str){
                time=min(time, cnt[ch-'a']);
            }

            for(char ch: str){
                cnt[ch-'a']-=time;
            }

            rec[num]=time;
        }

        string res="";
        for(int i=0; i<rec.size(); i++){
            for(int j=0;j<rec[i]; j++){
                res+=(char)('0'+i);
            }
        }
        return res;

    }
};





int main(){
    return 0;
}

