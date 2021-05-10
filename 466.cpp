/*
 * 466.cpp
 * Copyright (C) 2021-05-10 pzy <pzy@pzy-B250M-Wind>
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int idx1=0;
        int idx2=0;
        int cnt1=0;
        int cnt2=0;

        //idx2, [cnt1, cnt2]
        unordered_map<size_t, pair<int, int>> rec;
        pair<int, int> pre_loop;
        pair<int, int> in_loop;
        pair<int, int> post_loop;
        while(true){
            do{
                if(s1[idx1]==s2[idx2]){
                    idx2=(idx2+1)%(int)s2.size();
                    if(idx2==0){
                        cnt2++;
                    }
                }
                idx1=(idx1+1)%(int)s1.size();
                if(idx1==0){
                    cnt1++;
                }

            }while(idx1!=0);

            //no recycle
            if(cnt1==n1){
                return cnt2/n2;
            }

            if(rec.count(idx2)){
                pre_loop={rec[idx2].first, rec[idx2].second};
                in_loop={cnt1, cnt2};
                break;
            }else{
                rec[idx2]=make_pair(cnt1, cnt2);
            }
        }

        //repreated patterns
        //n1 repeats for n1-pre_loop.first, n2 repreats for n2-pre.second
        int res=(in_loop.second-pre_loop.second)*((n1-pre_loop.first)/(in_loop.first-pre_loop.first));

        //pre
        res+=pre_loop.second;

        //post
        //s1 starts from idx1, s2 starts from idx2(0)
        //s1 still repreats for more ()
        int cnt1_left=(n1-pre_loop.first)%(in_loop.first-pre_loop.first);
        while(cnt1_left!=0){
            if(s1[idx1]==s2[idx2]){
                idx2=(idx2+1)%(int)s2.size();
                if(idx2==0){
                    res++;
                }
            }
            idx1=(idx1+1)%(int)s1.size();
            if(idx1==0){
                cnt1_left--;
            }
        }

        return res/n2;

    }
};





int main(){
    return 0;
}

