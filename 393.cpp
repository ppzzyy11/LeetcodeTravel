/*
 * 393.cpp
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
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0; i<data.size(); i++){
            if(data[i]<0||data[i]>=248||(data[i]>=128&&data[i]<=191)){
                return false;
            }
            if(data[i]<=127){
                continue;
            }else if(data[i]>=192&&data[i]<=223){
                for(int j=0; j<1; j++){
                    i++;
                    if(i==data.size()){
                        return false;
                    }
                    if(data[i]>=128&&data[i]<=191){
                        ;
                    }else{
                        return false;
                    }
                }
            }else if(data[i]>=224&&data[i]<=239){
                for(int j=0; j<2; j++){
                    i++;
                    if(i==data.size()){
                        return false;
                    }
                    if(data[i]>=128&&data[i]<=191){
                        ;
                    }else{
                        return false;
                    }
                }

            }else if(data[i]>=240&&data[i]<=247){
                for(int j=0; j<3; j++){
                    i++;
                    if(i==data.size()){
                        return false;
                    }
                    if(data[i]>=128&&data[i]<=191){
                        ;
                    }else{
                        return false;
                    }
                }
            }

        }
        return true;
    }
};





int main(){
    return 0;
}

