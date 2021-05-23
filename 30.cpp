/*
 * 30.cpp
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
    vector<int> findSubstring(string str, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> cnt;
        unordered_map<string, int> cnt2refer;
        for(const string& word: words){
            cnt2refer[word]++;
        }

        int len=words[0].size();
        int num=0;
        for(int s=0; s<len; s++){

            int i=s;
            num=0;
            cnt.clear();
            for(int j=0; j<words.size()&&i+len-1<str.size(); j++){
                string substr=str.substr(i,len);
                i=i+len;

                if(cnt2refer.count(substr)){
                    cnt[substr]++;
                    if(cnt[substr]<=cnt2refer[substr]){
                        num++;
                    }

                }
            }
            if(num==words.size()){
                //OK
                res.push_back(i-words.size()*words[0].size());
            }
            //the first possible concatenation is included

            while(i+len-1<str.size()){
                //minus left
                string substr2minu=str.substr(i-words.size()*words[0].size(), len);
                if(cnt2refer.count(substr2minu)){
                    cnt[substr2minu]--;
                    if(cnt[substr2minu]<cnt2refer[substr2minu]) {
                        num--;
                    }
                }

                //add right
                string substr2add=str.substr(i, len);
                if(cnt2refer.count(substr2add)){
                    cnt[substr2add]++;
                    if(cnt[substr2add]<=cnt2refer[substr2add]){
                        num++;
                    }
                }
                i=i+len;


                if(num==words.size()){
                    //OK
                    res.push_back(i-words.size()*words[0].size());
                }
            }

        }

        return res;

    }

};





int main(){
    return 0;
}

