/*
 * 638.cpp
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




class SolutionBF {
public:
    int MAX=11;
    //use vector<int>& needs to memorize the answer
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        int n=price.size();
        unordered_map<int, int> rec;
        rec[0]=0;
        vector<int> cnt(n, 0);
        while(add1(cnt, needs)){
            int idx=getNum(cnt);
            rec[idx]=0;
            //ordinary prices
            for(int i=0; i<cnt.size(); i++){
                rec[idx]+=price[i]*cnt[i];
            }

            for(int i=0; i<special.size(); i++){
                bool poss=true;
                for(int j=0; j<n; j++){
                    if(cnt[j]<special[i][j]){
                        poss=false;
                        break;
                    }
                }
                if(poss==true){
                    vector<int> tmp=cnt;
                    for(int j=0; j<n; j++){
                        tmp[j]-=special[i][j];
                    }
                    rec[idx]=min(rec[idx],special[i][n]+rec[getNum(tmp)] );
                }
            }
        }
        return rec[getNum(needs)];
    }

    int getNum(const vector<int>& nums){
        int res=0;
        for(int i=0; i<nums.size(); i++){
            res+=nums[i]*pow(i);
        }
        return res;
    }

    bool add1(vector<int>& nums, const vector<int>& needs){
        int add=1;
        for(int i=0; i<nums.size(); i++){
            nums[i]+=add;
            add=nums[i]/needs[i];
            nums[i]=nums[i]%needs[i];
        }
        return add==0;
    }

    unordered_map<int,int> p;
    int pow(int n){
        int N=n;
        if(p.count(n)){
            return p[n];
        }
        int num=MAX;
        int res=1;
        while(n){
            if(n&1){
                res*=num;
            }
            num=num*num;
            n=(n>>1);
        }
        return p[N]=res;
    }

};





int main(){
    return 0;
}

