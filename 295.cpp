/*
 * 295.cpp
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



bool minCmp(const int& a,  const int& b){//should a be placed after b?
    return a>=b;
}
class MedianFinder {

    vector<int> minHeap;//bigger values
    vector<int> maxHeap;//smaller values
public:
    /** initialize your data structure here. */
    MedianFinder() {
        minHeap.clear();
        maxHeap.clear();
    }

    void addNum(int num) {
        if(maxHeap.size()==0||minHeap.size()==0){
            pushMaxHeap(num);
            balance();
            return ;
        }



        int right=minHeap[0];
        int left=maxHeap[0];
        if(num<=left){
            //push to left, maxHeap
            pushMaxHeap(num);

        }else{
            //push to right, minHeap
            pushMinHeap(num);
        }
        balance();
    }

    double findMedian() {
        if(maxHeap.size()==minHeap.size()+1){
            return maxHeap[0];
        }

        return (maxHeap[0]+minHeap[0])/2.0;
    }

    int popMaxHeap(){
        pop_heap(maxHeap.begin(), maxHeap.end());
        int rtn=maxHeap.back();
        maxHeap.pop_back();
        return rtn;
    }

    void pushMaxHeap(int val){
        maxHeap.push_back(val);
        push_heap(maxHeap.begin(), maxHeap.end());
    }

    int popMinHeap(){
        pop_heap(minHeap.begin(), minHeap.end(), minCmp);
        int rtn=minHeap.back();
        minHeap.pop_back();
        return rtn;
    }

    void pushMinHeap(int val){
        minHeap.push_back(val);
        push_heap(minHeap.begin(), minHeap.end(), minCmp);
    }

    void balance(){
        if(minHeap.size()==maxHeap.size()||maxHeap.size()==minHeap.size()+1){
            return ;
        }

        if(minHeap.size()>maxHeap.size()){
            //extract from minHeap, push it into maxHeap
            while(minHeap.size()>maxHeap.size()){
                pushMaxHeap(popMinHeap());
            }
        }else{
            //extract from maxHeap, push it into minHeap
            while(maxHeap.size()>minHeap.size()+1){
                pushMinHeap(popMaxHeap());
            }
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */





int main(){
    return 0;
}

