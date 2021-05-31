/*
 * 302.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    int up=0, down=0, right=0, left=0;

public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        up=down=x;
        left=right=y;

        dfs(image, x, y);

        return (down-up+1)*(right-left+1);
    }

    void dfs(vector<vector<char>>& image, int x, int y){
        if(x<0||y<0||x>=image.size()||y>=image[0].size()){
            return ;
        }

        if(image[x][y]=='0'){
            return;
        }
        if(image[x][y]=='1'){
            up=min(up, x);
            down=max(down, x);
            left=min(left, y);
            right=max(right, y);
            image[x][y]='0';
            dfs(image, x+1, y);
            dfs(image, x-1, y);
            dfs(image, x, y+1);
            dfs(image, x, y-1);

        }
        return ;

    }

};





int main(){
    return 0;
}

