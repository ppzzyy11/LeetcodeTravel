/*
 * 186.cpp
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
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        int idx=0;
        while(idx<s.size()){
            int j=idx;
            while(j<s.size()&&s[j]!=' '){
                j++;
            }
            reverse(s, idx, j-1);
            idx=j+1;
        }

    }

    void reverse(vector<char>& s, int i, int j){
        if(i<0||j>=s.size()||i>j){
            return ;
        }
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};





int main(){
    return 0;
}

