
/*
    Same Tree
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3389/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
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

/*
    Solution using vector comparison
    Time: O(n+m)
    Space: O(n+m), extra memory space needed to store trees as vectors
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        int p_size = get_max_index(p, 0)+1;
        int q_size = get_max_index(q, 0)+1;
        
        vector<int> vp(p_size, INT_MIN);
        vector<int> vq(q_size, INT_MIN);
        
        preorder_traversal(p, vp, 0);
        preorder_traversal(q, vq, 0);
        
        return vp == vq;
    }
    
    int get_max_index(TreeNode* p, int index)
    {
        if (p == NULL)
            return 0;
            
        int left_max = get_max_index(p->left, index*2+1);
        int right_max = get_max_index(p->right, index*2+2);
        
        return max(index, max(left_max, right_max));
    }
    
    void preorder_traversal(TreeNode* p, vector<int>& v, int index)
    {
        if (p==NULL) return;
        
        v[index] = p->val;
        preorder_traversal(p->left, v, index*2+1);
        preorder_traversal(p->right, v, index*2+2);
    }
};

/*
    Recursive solution
    Time: O(n+m), since we touch each node once | The correct explanation is that we have O(branches^depth) => O(2^log.n) => O(n).
    Space: O(n+m), since we need the stack frame space to store the parameters.
*/
class Solution2 {
public:
    bool isSameTreeRec(TreeNode* p, TreeNode* q) {
        
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) false;

        return isSameTreeRec(p->left, q->left) && isSameTreeRec(p->right, q->right);
    }
};

/*
    BFS Iterative Solution
    Time: O(n+m)
    Space: O(n+m)
*/
class Solution3 {
public:
    bool areEqual(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) false;

        return true;
    };

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (!areEqual(p,q)) return false;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty())
        {
            TreeNode* n1 = q1.front();
            TreeNode* n2 = q2.front();
            q1.pop();
            q2.pop();

            if (!areEqual(n1, n2)) return false;

            if (n1) //it also holds for n2
            {
                if (!areEqual(n1->left, n2->left)) return false;
                if(n1->left)
                {
                    q1.push(n1->left);
                    q2.push(n2->left);
                }

                if(!areEqual(n1->right, n2->right)) return false;
                if (n1->right)
                {
                    q1.push(n1->right);
                    q2.push(n2->right);
                }
            }
        }

        return true;
    }
};

int main()
{
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);

    Solution3 s;
    cout << "Is Same: " << to_string(s.isSameTree(a, b)) << endl;

    b->right->right = new TreeNode(4);
    cout << "Is Same: " << to_string(s.isSameTree(a, b)) << endl;

    return 0;
}