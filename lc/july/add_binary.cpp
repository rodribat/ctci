
/*
    Add Binady
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/
*/

#include<iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a.size() > b.size())
        {
            string prefix = "";
            for (int i=0; i<a.size()-b.size(); ++i)
                prefix += "0";
            b = prefix + b;
        }
        else
        {
            string prefix = "";
            for (int i=0; i<b.size()-a.size(); ++i)
                prefix += "0";
            a = prefix + a;
        }
        
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        
        char carry = '0';
        string result(a.size(), '0');
        for (int i=a.size()-1; i>=0; --i)
        {
            if (a[i]=='1' && b[i]=='1' && carry=='1')
            {
                carry = '1';
                result[i] = '1';
                continue;
            }
            
            if (a[i]=='0' && b[i]=='0' && carry=='1')
            {
                carry = '0';
                result[i] = '1';
                continue;
            }
            
            if ((a[i]=='1' || b[i]=='1') && carry=='1')
            {
                carry = '1';
                result[i] = '0';
                continue;
            }
            
            if (a[i]=='1' && b[i]=='1' && carry=='0')
            {
                carry = '1';
                result[i] = '0';
                continue;
            }
            
            if (a[i]=='0' && b[i]=='0' && carry=='0')
            {
                carry = '0';
                result[i] = '0';
                continue;
            }
            
            if ((a[i]=='1' || b[i]=='1') && carry=='0')
            {
                carry = '0';
                result[i] = '1';
                continue;
            }
        }
        
        if (carry=='1')
            result = carry + result;
        
        return result;
        
    }
};

int main()
{
    Solution s;

    string a = "11";
    string b = "1";

    cout << s.addBinary(a, b) << endl;
    return 0;
}