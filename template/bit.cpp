/*
 * bit.cpp
 * Copyright (C) 2021-05-10 patreickstar <patreickstar@B-W11JMD6R-0508.local>
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


//set a bit
number |= 1UL << n;

//clear a bit
number &= ~(1UL << n);

//toggle a bit
number ^= 1UL << n;

//checking a bit
bit = (number >> n) & 1U;

//Changing the nth bit to x
number ^= (-x ^ number) & (1UL << n);






int main(){
    return 0;
}

