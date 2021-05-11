/*
 * 418.cpp
 * Copyright (C) 2021-05-08 pzy <pzy@pzy-B250M-Wind>
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
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n=sentence.size();
        //start with ith word, counts and next started word
        vector<int> cnt(n, 0);
        vector<int> nxt(n, 0);

        for(int i=0; i<n; i++){
            int count=0;
            int remains=cols;
            int idx=i;
            while(remains>0){
                if(remains>=sentence[idx].size()){
                    remains-=sentence[idx].size()+1;
                    idx++;
                    if(idx==n){
                        idx=0;
                        count++;
                    }
                }else{
                    break;
                }
            }
            cnt[i]=count;
            nxt[i]=idx;
        }


        int count=0;
        int idx=0;
        for(int i=0; i<rows; i++){
            count+=cnt[idx];
            idx=nxt[idx];
        }
        return count;

    }
};


class SolutionBF {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int res=0;
        int remain=cols;
        int idx=0;
        int row=rows;
        while(row>0){
            if((int)sentence[idx].size()<=remain){//use this row to fit sentance
                remain-=sentence[idx].size();
                //for space
                remain--;
                idx++;

                //post process idx
                if(idx==sentence.size()){
                    idx=0;
                    res++;
                }

            }else{//try to use next line
                remain=cols;
                row--;
                if(idx==0){//repreated
                    if(rows!=row&&row!=0){
                        res=res+res*(row/(rows-row));
                        row=rows%row;
                    }else{
                        res++;
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

