/*
 * 68.cpp
 * Copyright (C) 2021-05-18 pzy <pzy@pzy-B250M-Wind>
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int s=0;
        while(s<words.size()){
            int e=s;
            int len=0;
            while(e<words.size()&&len+words[e].size()+e-s<=maxWidth){
                len+=words[e].size();
                e++;
                //[s,e)
            }

            string tmp="";
            //[s,e)
            if(e==words.size()){
                for(int i=s; i<e; i++){
                    tmp+=words[i];
                    if(i!=e-1)
                     tmp+=" ";

                }
                while(tmp.size()<maxWidth){
                    tmp=tmp+' ';
                }
            }else{
                if(s+1==e){
                    tmp+=words[s];
                    while(tmp.size()<maxWidth){
                        tmp=tmp+' ';
                    }
                }else{
                    int spaces=maxWidth-len;
                    int aver=spaces/(e-s-1);
                    int extra=spaces%(e-s-1);
                    for(int i=s; i<e; i++){
                        tmp+=words[i];
                        if(i!=e-1){
                            for(int j=0; j<aver; j++){
                                tmp+=" ";
                            }
                        }
                        if(extra-->0){
                            tmp+=" ";
                        }
                    }
                }
            }
            res.push_back(tmp);
            s=e;
        }

        return res;

    }
};





int main(){
    return 0;
}

