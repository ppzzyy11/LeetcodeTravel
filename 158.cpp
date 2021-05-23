/*
 * 158.cpp
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
    queue<char> que;
    //to delete
    char *buf4 = new char[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        while(que.size()<n){

            int cnt=read4(buf4);
            if(cnt==0){
                break;
            }
            for(int i=0; i<cnt; i++){
                que.push(buf4[i]);
            }

        }

        int i=0;
        for(;que.size()!=0&&i<n;i++){
            buf[i]=que.front();
            que.pop();
        }
        return i;
    }
};





int main(){
    return 0;
}

