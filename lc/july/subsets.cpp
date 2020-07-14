
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

    /* bit operations */
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

    /* recursive solution */
    vector<vector<int>> subsetsRec(vector<int>& nums) {
        if (nums.empty()) return {{}};

        int n = nums.back();
        nums.pop_back();

        cout << n << ", " << to_string(nums) << endl;

        vector<vector<int>> powerset = subsetsRec(nums);
        vector<vector<int>> new_subsets;
        for (vector<int> v: powerset)
        {
            vector<int> u(v);
            u.push_back(n);
            new_subsets.push_back(u);
        }

        powerset.insert(powerset.end(), new_subsets.begin(), new_subsets.end());

        return powerset;
    }

    /* iterative solution */
    vector<vector<int>> subsetsIt(vector<int>& nums) {
        vector<vector<int>> superset(1, vector<int>({}));
        for (int v:nums)
        {
            vector<vector<int>> new_subsets;
            for (vector<int> s:superset)
            {
                vector<int> u(s);
                u.push_back(v);
                new_subsets.push_back(u);
            }
            superset.insert(superset.end(), new_subsets.begin(), new_subsets.end());
        }
        return superset;
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
    for (vector<int> v:s.subsetsRec(set))
        cout << s.to_string(v) << endl;
    return 0;
}