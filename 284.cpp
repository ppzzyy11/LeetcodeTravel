/*
 * 284.cpp
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

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int nxt;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        nxt=INT_MIN;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(nxt!=INT_MIN){
            ;
        }else{
            nxt=Iterator::next();
        }
        return nxt;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int val=0;
        if(nxt!=INT_MIN){
            val=nxt;
            nxt=INT_MIN;
        }else{
            val=Iterator::next();
        }
        return val;
	}

	bool hasNext() const {
        if(nxt==INT_MIN){
            return Iterator::hasNext();
        }else{
            return true;
        }
	}
};




int main(){
    return 0;
}

