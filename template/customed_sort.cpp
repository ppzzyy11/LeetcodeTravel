/*
 * customed_sort.cpp
 * Copyright (C) 2021-05-02 pzy <pzy@pzy-B250M-Wind>
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

//There are three ways to define customed sorting.


//对vector中的 pair排序

vector<pair<int,char>>V;
bool cmp(const pair<int,char> a, const pair<int ,char> b)
{
    return a.first<b.first;            /// first 小的在前
}
sort(V.begin(),V.end(),cmp);

//priority_queue 存放 结构体
struct node
{
  int v, x;
  bool operator <(const node &b)const
    {
        return v < b.v; //大的先弹出
    }

};
priority_queue <node> Q;


// 优先队列中使用 pair , 自定义排序
#define pii pair<int,int>
struct cmp
{
    bool operator() (const pii p1,const pii p2)
    {
        return p1.first > p2.first;         // first 小的先弹出
    }
};
priority_queue<pii,vector<pii>,cmp> Q;


int main(){
    return 0;
}

