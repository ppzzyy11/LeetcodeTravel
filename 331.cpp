/*
 * 331.cpp
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
    bool isValidSerialization(string preorder) {
        //get vector<string>
        vector<string> strs=split(preorder, ',');
        int cnt=1;
        for(int i=0; i<strs.size(); i++){
            const string& str=strs[i];
            cnt--;
            if(str=="#"){
                ;
            }else{
                cnt+=2;
            }
            if(cnt<=0){
                return i==strs.size()-1;
            }
        }


        return cnt==0;
    }

    vector<string> split(string preorder, char ch){
        vector<string> res;
        int s=0;
        while(s<preorder.size()){
            int e=s;
            while(e<preorder.size()&&preorder[e]!=ch){
                e++;
            }
            res.push_back(preorder.substr(s, e-s));
            s=e+1;
        }

        return res;
    }
};





int main(){
    return 0;
}

