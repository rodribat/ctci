
/*
    Plus One
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        
        for (int i=digits.size()-1; i>=0; i--)
        {
            int d = digits[i];
            digits[i] = (d + carry) % 10;
            carry = (d + carry) / 10;
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

int main()
{
    vector<int> v({9,8,1});
    Solution s;
    s.plusOne(v);

    for (int i=0; i<v.size(); ++i)
        cout << to_string(v[i]) << ", ";
    
    cout << endl;

    return 0;
}