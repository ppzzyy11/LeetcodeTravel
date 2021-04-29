/*
 * 870.cpp
 * Copyright (C) 2021-04-29 pzy <pzy@pzy-B250M-Wind>
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


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        queue<int> idx = sortByIndex(B);
        queue<int> cpy=idx;

        sort(A.begin(), A.end());
        queue<int> aque;
        for(int i=0; i<A.size(); i++){
            aque.push(A[i]);
        }
        aque.push(-1);

        vector<int> res;
        while(aque.size()!=0&&aque.front()!=-1){
            if(aque.front()>B[idx.front()]){
                res.push_back(aque.front());
                aque.pop();
                idx.pop();
            }else{
                aque.push(aque.front());
                aque.pop();
            }
        }

        aque.pop();

        while(aque.size()!=0){
            res.push_back(aque.front());
            aque.pop();
        }

        vector<int> tmp=res;
        for(int i=0; i<res.size(); i++){
            res[cpy.front()]=tmp[i];
            cpy.pop();
        }
        return res;
    }

    queue<int> sortByIndex(const vector<int>& nums){
        vector<int> idxs(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            idxs[i]=i;
        }

        sort(idxs.begin(), idxs.end(), [&](const int&a, const int& b){
                return nums[a]<nums[b];
                });

        queue<int> que;
        for(auto idx: idxs){
            que.push(idx);
        }

        return que;
    }
};





int main(){
    return 0;
}

