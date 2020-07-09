
/*
    3 Sum
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:

    /*
        Despite this solution be O(n²), this algorithm didn't passed because
        the conversion from set to vector included some overhead.
    */
    vector<vector<int>> threeSum_v1(vector<int>& nums) {
        
        set<vector<int>> solution;
        for (int x=0; x<nums.size(); ++x)
        {
            set<int> s;
            for (int i=0; i<nums.size(); ++i)
            {
                if (i!=x)
                {
                    int targetSum = -nums[x];
                    if (s.find(nums[i]) != s.end())
                    {
                        //add to solution vector
                        vector<int> v({nums[x], nums[i], targetSum-nums[i]});
                        sort(v.begin(), v.end());
                        
                        if (solution.find(v) == solution.end())
                            solution.insert(v);
                    }
                    s.insert(targetSum-nums[i]);
                }
            }
        }
        
        return vector<vector<int>>(solution.begin(), solution.end());
    }

    /*
        This algorithm passed handling duplicates while increment the indexes.
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        if (n<3) return {};
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; ++i)
        {
            if (i==0 || nums[i]!=nums[i-1])
            {
                int j = i + 1;
                int k = n - 1;
                
                while(j<k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum==0)
                    {
                        result.push_back({nums[i], nums[j], nums[k]});
                        while (j<k && nums[j] == nums[j+1])
                            j++;
                        while (j<k && nums[k] == nums[k-1])
                            k--;
                        
                        j++; k--;
                    }
                    else if (sum>0) k--;
                    else j++;
                }
            }
        }
        return result;
    }

    static string to_string(const vector<int>& nums)
    {
        string s;
        for (int i=0; i<nums.size(); ++i)
            s += std::to_string(nums[i]) + ", ";
        return s;
    }
};

int main()
{
    Solution s;

    vector<int> nums({-1,0,1,2,-1,-4});
    vector<vector<int>> ans = s.threeSum(nums);

    for (vector<int> v:ans)
        cout << Solution::to_string(v) << endl;
    
    return 0;
}