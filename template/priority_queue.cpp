/*
 * priority_queue.cpp
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

using namespace std;



#include <functional>

using namespace std;

struct Node{
    int f;
    bool operator<(const Node& node) const{
        return f < node.f;
    }
};

class cmp{
    public:
        //less
        bool operator()(const Node& n1, const Node& n2) const{
            return n1 < n2;
        }
};

int main(){

    //default max heap
    priority_queue<Node, vector<Node>, cmp> q;
    Node n1; n1.f = 5;
    Node n2; n2.f = 4;
    Node n3; n3.f = 3;
    Node n4; n4.f = 2;
    Node n5; n5.f = 1;

    q.push(n1);q.push(n2);q.push(n3);q.push(n4);q.push(n5);

    while (!q.empty()){
        cout << q.top().f << endl;
        q.pop();
    }

    return 0;
}

