/*
 * 218.cpp
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
            template<class T>
            bool operator()(const vector<T>& nums1, const vector<T>& nums2){
                return nums1[0]>nums2[0];
            }
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_map<int, int> cnt;
        priority_queue<int> heights;//max
        heights.push(0);
        priority_queue<vector<long>, vector<vector<long>>, cmp> ops;//min heap
        for(const vector<int>& building: buildings){
            int s=building[0];
            int e=building[1];
            int h=building[2];
            ops.push({s, h});
            ops.push({e, -h});
        }

        queue<vector<int>> que;
        while(ops.size()){
            vector<long> op=ops.top();
            int idx=op[0];
            long h=op[1];
            ops.pop();
            if(h>0){
                if(heights.top()<h){
                    que.push({idx, (int)h, (int)h});
                }
                //push
                cnt[h]++;
                heights.push(h);
            }else{
                int old_height=heights.top();

                //pop
                cnt[-h]--;
                while(heights.size()!=1&&cnt[heights.top()]==0){
                    heights.pop();
                }

                if(heights.top()!=old_height){
                    que.push({idx, heights.top(), (int)h});
                }

            }
        }
        int idx=-1;
        bool pos=false;
        int h=0;
        vector<vector<int>> res;
        while(que.size()){
            vector<int> f=que.front();
            que.pop();
            idx=f[0];
            pos=f[2]>0;
            h=f[1];
            while(que.size()&&que.front()[0]==idx){
                f=que.front();
                que.pop();
                pos|=f[2]>0;
                if(pos){
                    h=max(h, f[1]);
                }else{
                    h=min(h, f[1]);
                }
            }
            if(res.size()==0||(res.size()&&h!=res.back()[1]))
                res.push_back({idx, h});
        }
        return res;
    }
};





int main(){
    return 0;
}

