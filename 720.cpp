/*
 * 720.cpp
 * Copyright (C) 2021-04-26 pzy <pzy@pzy-B250M-Wind>
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


class MyCalendar {
    map<int, int> mem;//<end, start>
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = mem.upper_bound(start);//find the first one ends after [start,end)
        if(it!=mem.end()&&it->second<end){
            return false;
        }else{
            mem[end]=start;
            return true;
        }

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */





int main(){
    return 0;
}

