/*
 * 483.cpp
 * Copyright (C) 2021-05-25 pzy <pzy@pzy-B250M-Wind>
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
    string smallestGoodBase(string n) {
        string k="2";
        while(bigger(k, n)){
            if(possible(k, n)){
                return k;
            }
            k=add(k, "1");
        }
        return "-1";
    }


    bool possible(string k, string target){
        string res="0";
        string kk=k;
        while(bigger(target, res)){
            res=add(res, kk);
            kk=multi(kk, k);
        }
        return !bigger(res, target)&&!bigger(target, res);

    }

    string multi(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> nums(max(num1.size(), num2.size())+1, 0);

        for(int i=0; i<num1.size(); i++){
            for(int j=0; j<num2.size(); j++){
                nums[i+j]=num1[i]*num2[j];
            }
        }

        int add=0;
        for(int i=0; i<nums.size(); i++){
            nums[i]+=add;
            add=nums[i]/10;
            nums[i]=nums[i]%10;
        }
        while(nums.size()>1&&nums.back()==0){
            nums.pop_back();
        }

        string res="";
        for(int i=nums.size()-1; i>=0; i--){
            res+=nums[i]+'0';
        }

        return res;
    }

    string add(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res="";

        int add=0;
        int idx=0;
        while(add!=0||idx<num1.size()||idx<num2.size()){
            int num=add;
            add=0;

            if(idx<num1.size()){
                num+=num1[idx]-'0';
            }

            if(idx<num2.size()){
                num+=num2[idx]-'0';
            }

            add=num/10;
            num=num/10;

            res+='0'+num;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    bool bigger(string num1, string num2){
        if(num1.size()!=num2.size()){
            return num1.size()>num2.size();
        }

        for(int i=0; i<num1.size(); i++){
            if(num1[i]!=num2[i]){
                return num1[i]>num2[i];
            }
        }
        return false;
    }
};





int main(){
    return 0;
}

