/*
 * 85.cpp
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

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        if(matrix.size()==0){
            return res;
        }

        vector<int> heights(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }else{
                    heights[j]++;
                }
            }
            res=max(res,getMaxRectangele(heights));
        }
        return res;
    }


private:
    int getMaxRectangele(vector<int> heights){
        heights.push_back(0);
        reverse(heights.begin(), heights.end());
        heights.push_back(0);
        reverse(heights.begin(), heights.end());
        int res=0;

        stack<int> st;
        for(int i=0; i<heights.size(); i++){
            while(st.size()!=0&&heights[st.top()]>heights[i]){
                int top =st.top();
                st.pop();
                //remember to -1
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
