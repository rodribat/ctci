
/*
    Subsets
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> solution;
        
        for (int i=0; i<=pow(2,nums.size())-1; ++i)
        {
            vector<int> subset;
            
            for (int j=0; j<nums.size(); ++j)
            {
                if (i & (1 << j))
                {
                    int v = nums[j];
                    subset.push_back(v);
                }
            }
            
            solution.push_back(subset);
        }
        
        return solution;
    }

    string to_string(const vector<int> &nums)
    {
        string s = "[";
        for (int n: nums)
            s += std::to_string(n) + ", ";
        s += "]";
        return s;
    }
};

int main()
{
    Solution s;
    vector<int> set({1,2,3});
    for (vector<int> v:s.subsets(set))
        cout << s.to_string(v) << endl;
    return 0;
}