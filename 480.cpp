/*
 * 480.cpp
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
    class cmp{
        public:
        bool operator()(int a, int b){
            return a>b;
        }
    };
    //left
    priority_queue<int> maxH;
    unordered_map<int, int> maxCnt;
    int cntMax=0;


    //right
    priority_queue<int, vector<int>, cmp> minH;
    unordered_map<int, int> minCnt;
    int cntMin=0;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i=0; i<k; i++){
            if(cntMax==0){
                maxPush(nums[i]);
            }else if(cntMin==0){
                minPush(nums[i]);
            }else{
                if(nums[i]>=getMedian()){
                    minPush(nums[i]);
                }else{
                    maxPush(nums[i]);
                }

            }
            balance();
        }
        vector<double> res;
        res.push_back(getMedian());

        for(int i=k; i<nums.size(); i++){
            if(maxCnt.count(nums[i-k])&&maxCnt[nums[i-k]]!=0){
                maxPop(nums[i-k]);
            }else{
                minPop(nums[i-k]);
            }

            if(nums[i]>=getMedian()){
                minPush(nums[i]);
            }else{
                maxPush(nums[i]);
            }
            balance();
            res.push_back(getMedian());
        }

        return res;
    }

    double getMedian(){
        if(cntMax==cntMin){
            return cntMax==0?(INT_MAX):((long)minH.top()+(long)maxH.top())/2.0;
        }
        return maxH.size()?maxH.top():INT_MAX;

    }

    void minPop(int num){
        cntMin--;
        minCnt[num]--;
        while(minH.size()&&minCnt[minH.top()]==0){
            minH.pop();
        }
    }

    void minPush(int num){
        cntMin++;
        minCnt[num]++;
        if(minCnt[num]==1){
            minH.push(num);
        }
    }

    void maxPop(int num){
        cntMax--;
        maxCnt[num]--;
        while(maxH.size()&&maxCnt[maxH.top()]==0){
            maxH.pop();
        }
    }

    void maxPush(int num){
        cntMax++;
        maxCnt[num]++;
        if(maxCnt[num]==1){
            maxH.push(num);
        }
    }

    void balance(){
        while(cntMax>cntMin+1){
            int top=maxH.top();
            maxPop(top);
            minPush(top);
        }

        while(cntMax<cntMin){
            int top=minH.top();
            minPop(top);
            maxPush(top);
        }
    }
};





int main(){
    return 0;
}

