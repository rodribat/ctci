
/*
    Word Search
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/

    Complexity:
    Time:
        let n: board size
            s: word size
        O(m*n*4^s)
    Space: O(m*n) - it could be transformed in O(1) if we codify visited status in input matrix (char-65 for visited and char+65 for unvisited)
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    // from: start(0), right(1), down(2), left(3), up(4)
    bool findRec(vector<vector<char>>& board, string word, int x, int y, set<pair<int,int>>& visited)
    {
        //cout << "Comparing " << board[y][x] << " = " << word[0] << " at (" << x << "," << y << ")" << endl;
        
        if (board[y][x] != word[0])
            return false;
        
        //cout << "Matched " << word[0] << endl;
        
        word = word.substr(1, word.size()-1);
        visited.insert(pair<int,int>(x,y));
        
        //cout << "New word: " << word << endl;
        
        if (word=="")
            return true;
        
        if (x<board[0].size()-1 && visited.find(pair<int,int>(x+1,y)) == visited.end())
        {
            //cout << "Going right" << endl;
            if (findRec(board, word, x+1, y, visited))
                return true;
        }
        
        if (x>0 && visited.find(pair(x-1,y)) == visited.end())
        {
            //cout << "Going left" << endl;
            if (findRec(board, word, x-1, y, visited))
                return true;
        }
        
        if (y<board.size()-1 && visited.find(pair<int,int>(x,y+1)) == visited.end())
        {
            //cout << "Going down" << endl;
            if (findRec(board, word, x, y+1, visited))
                return true;
        }
        
        if (y>0 && visited.find(pair<int,int>(x,y-1)) == visited.end())
        {
            //cout << "Going up" << endl;
            if (findRec(board, word, x, y-1, visited))
                return true;
        }
        
        visited.erase(pair<int,int>(x,y));
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); ++j)
            {
                set<pair<int,int>> visited;
                if (findRec(board, word, j, i, visited))
                    return true;
            }
        
        return false;
    }
};

int main()
{
    Solution s;



    return 0;
}