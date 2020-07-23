
/*
    Binary Tree Zigzag Level Order Traversal
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        bool invert = false;
        
        while (!Q.empty())
        {
            int n = Q.size();
            
            vector<int> current_level;
            for (int i=0; i<n; ++i)
            {
                TreeNode* n = Q.front();
                if (n->left != nullptr) Q.push(n->left);
                if (n->right != nullptr) Q.push(n->right);
            
                current_level.push_back(n->val);
                
                Q.pop();
            }
            
            if (invert)
                std::reverse(current_level.begin(), current_level.end());
            
            invert = !invert;
            
            result.push_back(current_level);
        }
        
        return result;
    }
};