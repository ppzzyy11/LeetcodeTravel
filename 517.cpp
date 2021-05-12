/*
 * 517.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum=0;
        for(int i=0; i<machines.size(); i++){
            sum+=machines[i];
        }
        if(sum%n!=0){
            return -1;
        }

        int d=sum/n;

        int res=0;
        int target=0;
        while(oK(machines, d)){

            int cur_sum=0;
            bool pre_minus=false;
            bool cur_minus=false;
            bool nxt_minus=false;
            for(int i=0; i<n; i++){
                cur_sum+=machines[i];
                target+=d;
                if(cur_sum<target&&nxt_minus==false){
                    machines[i]++;
                    machines[i+1]--;
                    nxt_minus=true;
                    cur_sum++;
                }else if(cur_sum>target&&cur_minus==false){
                    machines[i]--;
                    cur_minus=true;
                    machines[i+1]++;
                    cur_sum--;
                }

                pre_minus=cur_minus;
                cur_minus=nxt_minus;
                nxt_minus=false;
            }
        }



    }

    bool oK(const vector<int>& nums, int d){
        for(const int& num: nums){
            if(num!=d){
                return false;
            }
        }
        return true;
    }
};


//reverse way, solve the problem in a more complex way, alougth same TC
class Solution2 {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        vector<int> target_prefix(n, 0);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=machines[i];
            target_prefix[i]=sum;
        }
        if(sum%n!=0){
            return -1;
        }
        vector<int> cur(n, sum/n);
        vector<int> pre(n, sum/n);
        int res=0;
        while(cur!=machines){
            pre=cur;
            res++;
            vector<int> pre_prefix(n, 0);
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=pre[i];
                pre_prefix[i]=sum;
            }

            //no allowed t ++ two times
            for(int i=0;i<pre_prefix.size(); i++){
                if(target_prefix[i]<pre_prefix[i]){
                    cur[i]--;
                    cur[i+1]++;
                }else if(target_prefix[i]>pre_prefix[i]){
                    if(cur[i]==pre[i]) {
                        cur[i]++;
                        cur[i+1]--;
                    }
                }
            }
        }

        return res;


    }
};





int main(){
    return 0;
}

