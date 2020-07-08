
/*
    Arrange Coins
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
*/

#include<iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        
        int k=1;
        while (n>=k)
        {
            n = n-k;
            k++;
        }
        return k-1;
    }
};

int main()
{
    Solution s;
    cout << "k: " << s.arrangeCoins(5) << endl;

    return 0;
}