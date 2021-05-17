/*
 * 43.cpp
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
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size(), 0);
        for(int i=0; i<num1.size(); i++){
            for(int j=0;j<num2.size(); j++){
                int idx=(num1.size()-1-i+num2.size()-1-j);
                res[idx]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        int add=0;
        for(int i=0; i<res.size(); i++){
            res[i]+=add;
            add=res[i]/10;
            res[i]=res[i]%10;
        }

        while(res.size()>1&&res.back()==0){
            res.pop_back();
        }

        string str="";
        for(int i=res.size()-1; i>=0; i--){
            str=str+(char)(res[i]+'0');
        }

        return str;

    }
};





int main(){
    return 0;
}

