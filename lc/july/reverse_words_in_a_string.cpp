
/*
    Reverse Words in a String
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/
*/

#include<iostream>

using namespace std;

/*
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    string reverseWords(string s) {
        
        string word;
        string result;
        s = " " + s + " ";
        bool reading_word = false;
        for (int i=1; i<s.size(); ++i)
        {
            if (s[i-1]==' ' && s[i]!=' ') //beginning of word
                reading_word = true;
            
            if (s[i-1]!=' ' && s[i]==' ') //end of word
            {
                if (result != "")
                    result = " " + result;
                
                result = word + result;
                word = "";
                
                reading_word = false;
            }

            if (reading_word)
                word += s[i];
        }
        return result;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
class Solution2 {
public:
    string reverseWords(string s) {
        
        string result;
        int i = 0;
        int n = s.length();

        while (i<n)
        {
            while (i<n && s[i] == ' ') i++;
            if (i>=n) break;
            int j = i+1;
            while (j<n && s[j] != ' ') j++;
            string sub = s.substr(i, j-i);

            if (result.length()==0) result = sub;
            else result = sub + " " + result;

            i = j+1;
        }

        return result;
    }
};

int main()
{
    Solution s;

    string r = "the sky is blue";
    cout << r << endl << s.reverseWords(r) << endl;

    r = "  hello world!  ";
    cout << endl << r << endl << s.reverseWords(r) << endl;

    r = "a good   example";
    cout << endl << r << endl << s.reverseWords(r) << endl;

    return 0;
}