/*
 * 90.cpp
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
 *      To optimize:
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

using namespace std;



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        res.push_back(path);
        recur(res, path, nums, 0);
        return res;
    }

    void recur(vector<vector<int>>& res, vector<int>& path, const vector<int>& nums, int s){
        if(s==nums.size()){
            if(path.size()!=0)
                res.push_back(path);
            return ;
        }



        int e=s;
        if(s!=nums.size()-1&&nums[s]==nums[s+1]){
            //burden the Time Complexicty
            while(e<nums.size()-1&&nums[e]==nums[e+1]){
                e++;
            }
        }
        for(int i=s; i<e; i++){
            path.push_back(nums[s]);
        }
        recur(res, path, nums, e+1);
        for(int i=s; i<e; i++){
            path.pop_back();
        }
        //no this s
        recur(res, path, nums, s+1);
    }
};


//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class SolutionOfficial {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        //This way of backtarcking is better when all number all same
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};





int main(){
    return 0;
}
