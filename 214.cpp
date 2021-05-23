/*
 * 214.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    string shortestPalindrome(string s) {
        if(s.size()==0){
            return "";
        }
        string rs=s;
        reverse(rs.begin(), rs.end());
        int len=0;
        KMPAlgorithm(rs, s, len);
        string res=s.substr(len);
        reverse(res.begin(), res.end());
        return res+s;
    }

    void KMPAlgorithm(const string& txt,const string& pat, int& len)
    {
        vector<int> lps(pat.size(),0);
        int i=1,j=0;

        while(i<pat.size())//compute lps for pat
        {
            if(pat[i]==pat[j])
            {
                j++;//j forward
                lps[i]=j;
                i++;
            }else if(j!=0)//j decrease
            {
                j=lps[j-1];
            }else
            {
                i++;
            }
        }
        //pre process done


        //Begin to search
        i=j=0;

        while(i<txt.size())
        {
            if(pat[j]==txt[i])
            {
                i++;//j forward
                j++;
            }
            if(i==txt.size())
            {
                break;
            }
            if(j==pat.size())
            {
                //cout<<"Found at index :"<<i-j<<endl;//found
                j=lps[j-1];
            }else if(i<txt.size()&&pat[j]!=txt[i])
            {
                if(j==0)// j decrease
                {
                    i++;
                }else
                {
                    j=lps[j-1];
                }
            }
        }
        //j is the len
        len=j;
    }
};





int main(){
    return 0;
}

