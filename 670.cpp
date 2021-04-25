/*
 * 670.cpp
 * Copyright (C) 2021-04-25 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        unordered_map<char, int> mem;
        for(int i=str.size()-1; i>=0; i--){
            if(mem.count(str[i])==0){
                mem[str[i]]=i;
            }
        }

        //attention i<str.size()-1
        for(int i=0; i<str.size()-1; i++){
            //attention ch > str[i]
            for(char ch='9'; ch>str[i]; ch--){
                if(mem.count(ch)&&mem[ch]>i){
                    swap(str[i], str[mem[ch]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }

};





int main(){
    return 0;
}

