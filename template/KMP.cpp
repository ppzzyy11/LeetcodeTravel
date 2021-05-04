/*
 * KMP.cpp
 * Copyright (C) 2021-05-04 pzy <pzy@pzy-B250M-Wind>
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



    vector<int> getnext(string s)
    {


        vector<int> next(t);
        int i = 0, j = -1;
        next[0] = -1;
        while (i<t-1)      //因为是算的next元素的前缀匹配数 小心越界
        {
            if (j==-1||s[i] == s[j])  //
            {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }
        return next;

    }
    int KMPMatch(string s1, string s2)
    {
        int t1 = s1.size();
        int t2 = s2.size();
        vector <int> next(getnext(s2));
        int i = 0, j = 0;
        while (i < t1&&j < t2)
        {
            if (j == -1 || s1[i] == s2[j])  //注意是j==-1；
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == t2)
            return i - j;
        return -1;
    }





int main(){
    return 0;
}

