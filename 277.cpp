/*
 * 277.cpp
 * Copyright (C) 2021-04-17 pzy <pzy@pzy-B250M-Wind>
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

using namespace std;


class Solution{
public:
    int findCelebrity(int n) {
        int candicate=0;

        //can this method ensure thath we can find out the candicate? Altrough there is only one celebrity.
        //Yes!
        //
        //if i know j, then i is not the celebrity, otherwise when i does not know j, j is not the celebrity.
        for(int i=1; i<n; i++){
            if(knows(candicate, i)){
                candicate=i;
            }
        }

        for(int i=0; i<n; i++){
            if(i==candicate){
                continue;
            }
            if(knows(candicate, i)||!knows(i, candicate)){
                return -1;
            }
        }

        return candicate;

    }
};


bool knows(int a, int b){
    return true;
}


/*
 * my solution is a O(N^2) travel.
 */


int main(){
    return 0;
}

