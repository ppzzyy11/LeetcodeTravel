/*
 * 241.cpp
 * Copyright (C) 2021-06-04 pzy <pzy@pzy-B250M-Wind>
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
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;

        for(int i=0; i<expression.size(); i++){
            if(isOperator(expression[i])){
                vector<int> left= diffWaysToCompute(expression.substr(0, i));
                vector<int> right= diffWaysToCompute(expression.substr(i+1));
                for(const int& l:left){
                    for(const int& r: right){
                        switch (expression[i]){
                            case '+':
                                res.push_back(l+r);
                                break;
                            case '-':
                                res.push_back(l-r);
                                break;
                            case '*':
                                res.push_back(l*r);
                                break;
                            case '/':
                                res.push_back(l/r);
                                break;
                        };
                    }
                }
            }
        }

        if(res.size()==0){
            res.push_back(stoi(expression));
        }
        return res;
    }

    bool isOperator(char ch){
        return ch=='-'||ch=='+'||ch=='*'||ch=='/';
    }
};





int main(){
    return 0;
}

