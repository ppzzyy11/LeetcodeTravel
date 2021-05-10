/*
 * 467.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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
    int findSubstringInWraproundString(string p) {
        int len=0;
        int ch=p[0];
        vector<int> rec(256, 0);
        for(int i=0; i<p.size(); i++){
            if(i!=0&&valid(p[i-1], p[i])){
                len++;
            }else{
                record(rec, ch, len);
                len=1;
                ch=p[i];
            }
            //cout<<(char)ch<<":"<<len<<endl;
        }
        record(rec, ch, len);

        int res=0;
        for(int i=0; i<rec.size(); i++){
            if(i>='a'&&i<='z'){
                //cout<<(char)i<<":"<<rec[i]<<endl;
            }
            res+=rec[i];
        }
        return res;

    }

    inline bool valid(char ch1, char ch2){
        int num1=ch1-'a';
        int num2=ch2-'a';
        return ( num1+1 )%26==num2;

    }

    void record(vector<int>& rec, char ch, int len){
        while(len>=0){
            rec[ch]=max(rec[ch], len);
            ch++;
            if(ch=='z'+1){
                ch='a';
            }
            len--;
        }
    }

};

// not unique
class Solution2 {
public:
    int findSubstringInWraproundString(string p) {
        int len=1;
        int res=0;
        for(int i=0; i<p.size()-1; i++){
            if(valid(p[i], p[i+1])){
                len++;
            }else{
                res+=(len+1)*len/2;
                len=1;
            }
        }
        res+=(len+1)*len/2;
        return res;

    }

    inline bool valid(char ch1, char ch2){
        int num1=ch1-'a';
        int num2=ch2-'a';
        return ( num1+1 )%26==num2;

    }
};





int main(){
    Solution s;
    cout<<s.findSubstringInWraproundString("yvedckyzrh");
    return 0;
}

