/*
 * 457.cpp
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


class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(detecCircle(nums, i)){
                return true;
            }
        }
        return false;

    }

    bool detecCircle(vector<int>& nums, int idx){
        vector<int> path;
        //fast, slow pointers
        int fast=idx, slow=idx;
        bool cicular=false;
        while(nums[fast]!=0&&nums[nxtIdx(nums, fast)]){
            path.push_back(slow);
            fast=nxtIdx(nums, nxtIdx(nums, fast));
            slow=nxtIdx(nums, slow);
            if(fast==slow){
                cicular=true;
                break;
            }
        }

        vector<int> cycle;
        if(cicular==false){
            set0Path(nums, path);
            return false;
        }else{
            //fast=idx;
            //while(fast!=slow){
                //fast=nxtIdx(nums, fast);
                //slow=nxtIdx(nums, slow);
            //}
            //slow is the start of cycle
            cycle=getCycle(nums, slow);
            bool res = legal(nums, cycle);
            set0Path(nums, path);
            set0Path(nums, cycle);
            return res;
        }


    }

    int nxtIdx(const vector<int>& nums, int idx){
        idx=(idx+nums.size())%nums.size();
        return (idx+nums[idx]+nums.size())%nums.size();

    }

    bool legal(vector<int>& nums, vector<int>& path){
        for(int i=0; i<path.size(); i++){
            int idx=path[i];
            if(nums[idx]==0){
                return false;
            }
            if(i>0){
                if(nums[path[i]]*nums[path[i-1]]<0){
                    return false;
                }
            }
        }

        return path.size()!=1;
    }

    void set0Path(vector<int>& nums, const vector<int>& idxs){
        for(auto idx: idxs){
            nums[idx]=0;
        }
    }

    vector<int> getCycle(const vector<int>& nums, int start){
        vector<int> cycle;
        int idx=start;
        do{
            cycle.push_back(idx);
            idx=nxtIdx(nums, idx);
        }while(idx!=start);
        return cycle;
    }
};





int main(){
    vector<int> nums{2,-1,1,2,2};
    return 0;
}

