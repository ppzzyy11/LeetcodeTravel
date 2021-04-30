/*
 * 926.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int minFlipsMonoIncr(string S) {
        int end0=0;
        int end1=0;
        for(auto ch:S){
            int nxtend0=0;
            int nxtend1=0;
            if(ch=='0'){
                nxtend0=end0;
                nxtend1=min(end0, end1)+1;
            }else{//ch=='1'
                nxtend0=end0+1;
                nxtend1=min(end0, end1);
            }
            end0=nxtend0;
            end1=nxtend1;
        }
        return min(end0, end1);

    }
};





int main(){
    return 0;
}

