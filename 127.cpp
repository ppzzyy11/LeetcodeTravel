/*
 * 127.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        vector<bool> visited(n, false);
        unordered_map<string, int> str2idx;

        for(int i=0; i<wordList.size(); i++){
            str2idx[wordList[i]]=i;
        }

        int step=1;

        queue<string> que;
        que.push(beginWord);
        if(str2idx.count(beginWord)!=0){
            visited[str2idx[beginWord]]=true;
        }


        while(que.size()){
            int size=que.size();
            step++;
            while(size-->0){
                string fnt=que.front();
                que.pop();

                string word=fnt;
                for(int i=0; i<fnt.size(); i++){
                    for(char ch='a'; ch<='z'; ch++){
                        fnt[i]=ch;
                        if(fnt==word){
                            //no change
                            continue;
                        }
                        //no in the list
                        if(str2idx.count(fnt)==0){
                            continue;
                        }

                        //in the list and not visited
                        if(visited[str2idx[fnt]]==false&&possible(word, fnt)){
                            if(fnt==endWord){
                                return step;
                            }
                            visited[str2idx[fnt]]=true;
                            que.push(fnt);
                        }
                    }
                    fnt[i]=word[i];
                }
            }
        }

        return 0;
    }

    bool possible(const string& str1, const string& str2){
        if(str1.size()!=str2.size()){
            return false;
        }
        int cnt=0;
        for(int i=0; i<str1.size(); i++){
            if(str1[i]!=str2[i]){
                cnt++;
            }
            if(cnt>1){
                return false;
            }
        }

        return true;
    }
};





int main(){
    return 0;
}

