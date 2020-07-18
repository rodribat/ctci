
/*
    Top K Frequent Elements
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if (nums.size() == k) return nums;
        
        unordered_map<int, int> dict;
        
        for (int i=0; i<nums.size(); ++i)
            dict[nums[i]]++;
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b)
        {
            return a.second < b.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> P(cmp);
        
        for (pair<int, int> p : dict)
            P.push(p);
        
        vector<int> result;
        for (int i=0; i<k; ++i)
        {
            result.push_back(P.top().first);
            P.pop();
        }
        
        return result;
    }
};

string to_string(vector<int> nums)
{
    string str;
    for (int n : nums)
        str += std::to_string(n) + ", ";
    return str;
}

int main()
{
    Solution s;
    vector<int> input({1,1,1,2,2,3});
    
    cout << to_string(s.topKFrequent(input, 2)) << endl;

    return 0;
}