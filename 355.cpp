/*
 * 355.cpp
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



class Twitter {
    unordered_map<int, vector<int>> id2follwers;

    int cnt=0;
    //it, time
    unordered_map<int, vector<pair<int, int>>> id2tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        id2tweets[userId].push_back(make_pair(tweetId, cnt++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;

        vector<int> ids=id2follwers[userId];
        ids.push_back(userId);

        vector<int> idxs(ids.size(), 0);
        for(int i=0; i<10; i++){
            int idx=-1;
            //try to get the newest tweet by idxs
            for(int i=0; i<idxs.size(); i++){
                if(idxs[i]<id2tweets[ids[i]].size()){
                    if(idx==-1){
                        idx=idxs[i];
                    }else if(id2tweets[ids[i]][idxs[i]].second>id2tweets[ids[idx]][idxs[idx]].second){
                        idx=idxs[i];
                    }
                }
            }
            if(idx==-1){
                break;
            }else{
                newsFeed.push_back(id2tweets[ids[idx]][idxs[idx]].first);
            }
        }

        return newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        id2follwers[followeeId].push_back(followerId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        vector<int>& followerIds = id2follwers[followeeId];
        int idx=0;
        while(idx<followerIds.size()&&followerIds[idx]!=followeeId){
            idx++;
        }
        if(idx<followerIds.size())
        {
            followerIds[idx]=followerIds.back();
            followerIds.pop_back();
        }

        return ;

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */





int main(){
    return 0;
}

