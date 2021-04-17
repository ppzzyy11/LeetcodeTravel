/*
 * 84.cpp
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
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        //push two boarder 0 to simplify the algorithm, all the two 0s are necessary
        heights.push_back(0);
        reverse(heights.begin(), heights.end());
        heights.push_back(0);
        reverse(heights.begin(), heights.end());

        stack<int> st;
        int res=0;

        for(int i=0; i<heights.size(); i++){
            while(st.size()!=0&&heights[st.top()]>heights[i]){
                int top = st.top();
                st.pop();
                res=max(res, heights[top]*(i-st.top()-1));
            }
            st.push(i);
        }

        return res;
    }
};






int main(){
    return 0;
}
