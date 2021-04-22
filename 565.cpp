/*
 * 565.cpp
 * Copyright (C) 2021-04-22 pzy <pzy@pzy-B250M-Wind>
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
    int arrayNesting(vector<int>& nums) {
        int res=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                continue;
            }
            int tmp=0;
            int rec_i=i;
            while(nums[i]>=0){
                tmp++;
                res=max(res, tmp);
                nums[i]=-nums[i];
                if(abs(nums[i])==i){
                    //
                    break;
                }
                i=abs(nums[i]);
            }
            i=rec_i;
        }

        return res;
    }
};





int main(){
    return 0;
}

