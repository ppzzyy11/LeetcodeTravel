/*
 * 281.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



class ZigzagIterator {
    vector<int> v1;
    vector<int> v2;
    int i1, i2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1=v1;
        this->v2=v2;
        i1=i2=0;
    }

    int next() {
        if(i1<v1.size()&&i2<v2.size()){
            return i1==i2?v1[i1++]:v2[i2++];
        }else if(i1<v1.size()){
            return v1[i1++];
        }else if(i2<v2.size()){
            return v2[i2++];
        }
        return -1;

    }

    bool hasNext() {
        return i1<v1.size()||i2<v2.size();

    }
};





int main(){
    return 0;
}

