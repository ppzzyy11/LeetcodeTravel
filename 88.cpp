/*
 * 88.cpp
 * Copyright (C) 2021-04-14 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
 *      To optimize:
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

using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //range from the biggest into the end of nums1 is much easier.
        int i=m-1, j=n-1;
        int k=m+n-1;
        while(i>=0||j>=0){
            if(i>=0&&j>=0){
                if(nums1[i]>nums2[j]){
                    nums1[k--]=nums1[i--];
                }else{
                    nums1[k--]=nums2[j--];
                }
            }else if(i>=0){
                nums1[k--]=nums1[i--];
            }else if(j>=0){
                nums1[k--]=nums2[j--];
            }
        }
    }
};




int main(){
    return 0;
}
