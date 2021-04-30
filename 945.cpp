/*
 * 945.cpp
 * Copyright (C) 2021-04-30 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> cnt;
        int sum2=0;
        for(int i=0; i<A.size(); i++){
            cnt[A[i]]++;
            if(cnt[A[i]]>1){
                sum2+=A[i];
            }
        }

        int cnt2inc=0;
        int sum1=0;
        for(int i=0; i<A.size(); i++){
            if(i!=0&&A[i]-A[i-1]>1&&cnt2inc>0){
                //insert here between [A[i-1]+1,A[i]-1]
                int target=A[i-1]+1;
                while(cnt2inc&&target<=A[i]-1){
                    cnt2inc--;
                    sum1+=target++;
                }
            }
            if(--cnt[A[i]]!=0){
                cnt2inc++;
            }
        }
        if(cnt2inc>0){
            int target=A.back()+1;
            while(cnt2inc-->0){
                sum1+=target++;
            }
        }
        return sum1-sum2;

    }
};





int main(){
    return 0;
}

