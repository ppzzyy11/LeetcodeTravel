/*
 * 336.cpp
 * Copyright (C) 2021-05-23 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        set<pair<int, int>> rec;
        unordered_map<string, int> str2idx;
        for(int i=0; i<words.size(); i++){
            str2idx[words[i]]=i;
        }

        for(int i=0; i<words.size(); i++){
            const string& word = words[i];
            int s=0, e=0;
            //from tail
            s=e=word.size()-1;
            while(s>=0&&e<word.size()){
                if(isP(word, s, e)){

                    string str=word.substr(0, s);
                    reverse(str.begin(), str.end());
                    if(word!=str&&str2idx.count(str)){
                        rec.insert(make_pair(i, str2idx[str]));
                    }
                }
                s--;
            }

            //from head
            s=e=0;
            while(s>=0&&e<word.size()){
                if(isP(word, s, e)){
                    string str=word.substr(e+1);
                    reverse(str.begin(), str.end());
                    if(str!=word&&str2idx.count(str)){
                        rec.insert(make_pair( str2idx[str],i));
                    }
                }
                e++;
            }

            string rword=word;
            reverse(rword.begin(), rword.end());
            if(rword!=word){
                if(str2idx.count(rword)){
                    rec.insert(make_pair(i, str2idx[rword]));
                }
            }
            if(word.size()!=0&&isP(word, 0, word.size()-1)){
                if(str2idx.count("")){
                    rec.insert(make_pair(i, str2idx[""]));
                    rec.insert(make_pair(str2idx[""], i));
                }
            }
        }
        for(auto it=rec.begin(); it!=rec.end(); it++){
            vector<int> tmp;
            tmp.push_back(it->first);
            tmp.push_back(it->second);
            res.push_back(tmp);
        }
        return res;

    }

    bool isP(const string& str, int s, int e){
        while(s<=e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

};





int main(){
    return 0;
}

