/*
 * 126.cpp
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



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;

        //learn how to initialize the data
        unordered_set<string> dict{wordList.begin(), wordList.end()};

        unordered_map<string, int> steps{{beginWord,0}};
        unordered_map<string, set<string>> from{{beginWord,{}}};

        int step =0;
        bool found= false;
        dict.erase(beginWord);
        queue<string> que{{beginWord}};
        while(que.size()){
            step++;
            int n =que.size();
            for(int i=0; i<n; i++){
                //for each word in the current layer

                const string word = que.front();
                que.pop();
                string nxtWord = word;

                for(int j=0; j<word.size(); j++){
                    for(char ch = 'a'; ch<='z'; ch++){
                        nxtWord[j]=ch;
                        if(nxtWord==word){
                            continue;
                        }

                        //if nxtWord is found in the same layer but get erased, record the from the process will end in the dict.find section.
                        //cout<<"step["<<nxtWord<<"]="<<steps[nxtWord]<<"\tstep="<<step<<"\n";
                        if(steps[nxtWord]==step){
                            from[nxtWord].insert(word);
                            //cout<<"from["<<nxtWord<<"].insert("<<word<<")\n";
                        }
                        if(dict.find(nxtWord)==dict.end()){
                            continue;
                        }

                        dict.erase(nxtWord);
                        //cout<<"erase "<<nxtWord<<"\n";

                        steps[nxtWord]=step;

                        que.push(nxtWord);

                        from[nxtWord].insert(word);
                        //cout<<"from["<<nxtWord<<"].insert("<<word<<")\n";
                        if(nxtWord==endWord){
                            found=true;
                        }
                    }
                    nxtWord[j]=word[j];
                }
            }
            if(found){
                break;
            }
        }

        if(found){
            vector<string> path ={endWord};
            reconstructPaths(res, path, from, endWord );

        }


        return res;

    }


    void reconstructPaths(vector<vector<string>>& res, vector<string>& path, unordered_map<string, set<string>>& from, string endWord){
        if(from[endWord].empty()){
            res.push_back({path.rbegin(), path.rend()});
            return ;
        }

        for(string parent: from[endWord]){
            path.push_back(parent);
            reconstructPaths(res, path, from, parent);
            path.pop_back();
        }
    }


};




int main(){
    Solution* so = new Solution();
    vector<string> dict {"hot","dot","dog","lot","log","cog"};
    so->findLadders("hit","cog",dict);


    return 0;
}

