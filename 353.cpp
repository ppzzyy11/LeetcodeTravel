/*
 * 353.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



class SnakeGame {

    struct pair_hash{
        template<class T1, class T2>
            size_t operator()(const pair<T1, T2>&p) const{
                size_t h1=hash<T1>()(p.first);
                size_t h2=hash<T2>()(p.first);
                return h1^h2;
            }
    };

    int w, h;
    vector<vector<int>> food;
    //idx of the food being displayed
    int idx;
    //current position of the sanke head.
    int x, y;
    queue<pair<int, int>> snakes;
    unordered_set<pair<int, int>, pair_hash> rec;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w=width;
        h=height;
        this->food=food;
        x=0,y=0;
        idx=0;
        snakes.push({x, y});
        rec.insert({x,y});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        //move
        if(direction=="U"){
            x--;
        }else if(direction=="D"){
            x++;
        }else if(direction=="L"){
            y--;
        }else if(direction=="R"){
            y++;
        }

        if(idx<food.size()&&x==food[idx][0]&&y==food[idx][1]){
            //not pop
            idx++;
        }else{

            //first pop
            pair<int, int> fnt=snakes.front();
            snakes.pop();

            rec.erase(rec.find(fnt));
        }

        //hit body
        if(rec.count({x, y})||x<0||y<0||x>=h||y>=w){
            return -1;
        }else{
            rec.insert({x,y});
            snakes.push({x, y});
        }


        return snakes.size()-1;

    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */





int main(){
    return 0;
}

