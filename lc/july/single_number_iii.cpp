
/*
    Single Number III
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/
*/

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        if (nums.size() == 1) return vector<int>({1,0});
        
        if (nums.size() == 2) return nums;
        
        unordered_set<int> S;
        for (int d:nums)
        {
            if (S.find(d) == S.end())
                S.insert(d);
            else
                S.erase(d);
        }
        
        vector<int> result;
        for (int d:S)
            result.push_back(d);

        return result;
    }
};

string to_string(const vector<int>& nums)
{
    string str;
    for (int d:nums)
        str += std::to_string(d) + ", ";
    return str;
}

int main(){
    Solution s;
    vector<int> nums({1,2,1,3,2,5});

    cout << to_string(s.singleNumber(nums)) << endl;

    return 0;
}