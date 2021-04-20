/*
 * 380.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.resize(0,0);
        rec.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(rec.find(val)!=rec.end()){
            return false;
        }
        nums.push_back(val);
        rec[val]=nums.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(rec.find(val)==rec.end()){
            return false;
        }
        int idx=rec[val];
        if(idx==nums.size()-1){
            nums.pop_back();
            rec.erase(val);
            return true;
        }

        swap(rec[val], rec[nums.back()]);
        swap(nums[idx], nums.back());
        nums.pop_back();
        rec.erase(val);
        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[random()%nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, size_t> rec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */





int main(){
    return 0;
}

