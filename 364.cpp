/*
 * 364.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
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



/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int dep=0;
        for(NestedInteger& ni: nestedList){
            dep=max(dep, getDepth(ni));
        }
        int res=0;
        for(NestedInteger& ni: nestedList){
            res+=getSum(ni, 1, dep);
        }
        return res;
    }

    int getSum(NestedInteger ni, int dep, int mD){
        if(ni.isInteger()){
            return (mD-dep+1)*ni.getInteger();
        }
        int res=0;
        vector<NestedInteger> list = ni.getList();
        for(const NestedInteger& ni: list){
            res+=getSum(ni, dep+1, mD);
        }
        return res;
    }

    int getDepth(NestedInteger ni){
        if(ni.isInteger())
            return 1;
        int dep=0;
        vector<NestedInteger>& list=ni.getList();
        for(const NestedInteger& ni: list){
            dep=max(dep, getDepth(ni));
        }
        return dep+1;
    }
};





int main(){
    return 0;
}

