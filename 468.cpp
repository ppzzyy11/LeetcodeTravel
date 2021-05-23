/*
 * 468.cpp
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
    string validIPAddress(string IP) {
        if(ipv4(IP)){
            return "IPv4";
        }
        if(ipv6(IP)){
            return "IPv6";
        }
        return "Neither";

    }

    bool ipv4(const string& ip){
        for(const int&ch :ip){
            if(ch=='.'||(ch>='0'&&ch<='9')){
                continue;
            }else{
                return false;
            }
        }
        vector<string> nums=getSplitStrs(ip, '.');
        if(nums.size()!=4){
            return false;
        }
        for(const string& num: nums){
            if(num.size()>1&&num[0]=='0'){
                return false;
            }
            if(num.size()<1||num.size()>3){
                return false;
            }
            int n=atoi(num.c_str());
            if(n>255||n<0){
                return false;
            }

        }
        return true;

    }

    bool ipv6(const string& ip){
        for(const int&ch :ip){
            if((ch==':'||(ch>='0'&&ch<='9')||(ch>='a'&&ch<='f')||(ch>='A'&&ch<='F'))){
                continue;
            }else{
                return false;
            }
        }

        vector<string> nums=getSplitStrs(ip, ':');
        if(nums.size()!=8){
            return false;
        }
        for(const string& num: nums){
            if(num.size()<=0||num.size()>4){
                return false;
            }

        }
        return true;

    }

    vector<string> getSplitStrs(const string& str, char ch){
        vector<string> res;
        int i=0;
        while(i<str.size()){
            if(str[i]==ch){
                if(i==0||i==str.size()-1||str[i-1]==ch){
                    res.push_back("");
                }
                i++;
                continue;
            }
            int j=i;
            while(j<str.size()&&str[j]!=ch){
                j++;
            }
            //[i,j)
            res.push_back(str.substr(i,j-i));
            i=j;
        }
        return res;
    }

};





int main(){
    Solution s;
    cout<<s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:")<<endl;;
    return 0;
}

