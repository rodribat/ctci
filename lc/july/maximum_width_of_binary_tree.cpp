/*
    Maximum Width of Binary Tree
    link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/
*/

#include<iostream>
#include<queue>
#include<limits.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> Q;

        // insert root on queue
        Q.push(make_pair(root, 0));

        // visit tree level by level holding the max
        int result = INT_MIN;
        while(!Q.empty())
        {
            // calculate current level width
            int start = Q.front().second;
            int end = Q.back().second;
            int width = end-start+1;
            result = max(result, width);

            // insert children on queue and pop the current level nodes
            int n = Q.size();
            for (int i=0; i<n; ++i)
            {
                pair<TreeNode*, int> p = Q.front();
                int idx = p.second-start;
                Q.pop();

                // visit children
                if (p.first->left) Q.push(make_pair(p.first->left, 2*idx+1));
                if (p.first->right) Q.push(make_pair(p.first->right, 2*idx+2));
            }
        }

        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->left = NULL;
    root->right->right = new TreeNode(9);

    Solution s;
    cout << "Width: " << s.widthOfBinaryTree(root) << endl;;

    return 0;
}