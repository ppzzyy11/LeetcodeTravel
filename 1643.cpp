/*
 * 1643.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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



class SolutionTLE {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int m=destination[0];
        int n=destination[1];
        string str="";
        while(--n){
            str+='H';
        }
        while(--m){
            str+='V';
        }

        while(--k){
            next_permutation(str.begin(), str.end());
        }

        return str;
    }
};





int main(){
    return 0;
}

