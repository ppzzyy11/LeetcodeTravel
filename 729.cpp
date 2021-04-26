/*
 * 729.cpp
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
    map<int, int> m;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = m.upper_bound(start);//the first ends after start
        if(it!=m.end()&&it->second<end){
            return false;
        }else{
            m[end]=start;
            return true;
        }

        return false;
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

