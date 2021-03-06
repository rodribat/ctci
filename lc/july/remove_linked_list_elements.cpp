
/*
    Remove Linked List Elements
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/
*/

#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    // recursive solution
    ListNode* removeElementsRecursive(ListNode* head, int val) {
        
        if (!head) return head;
        
        ListNode* n = removeElements(head->next, val);
        if (head->val == val) // if the current value needs to be removed - bypass current element returning next valid element returned in n;
            return n;
        else // current value don't need to be removed - update head->next and return current head
        {
            head->next = n;
            return head;
        }
    }

    // simpler solution
    ListNode* removeElementsSimpler(ListNode* head, int val) {
        
        if (!head) return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (!curr)
        {
            if (curr->val == val)
            {
                if (!prev) head = curr->next;
                else prev = curr->next;
            }
            else
                prev = curr;
                
            curr = curr->next;
        }
        
        return head;
    }

    ListNode* removeElements(ListNode* head, int val) {
        
        while (head != nullptr && head->val == val)
        {
            ListNode* n = head;
            head = head->next;
            
            delete n;
        }
        
        if (head==nullptr) return head;
        
        ListNode* n = head;
        while (n->next!=nullptr)
        {
            if (n->next->val == val)
            {
                ListNode* r = n->next;
                n->next = n->next->next;
                delete r;
            }
            else
                n = n->next;
        }
        
        return head;
    }

    string to_string(ListNode* head)
    {
        ListNode* n = head;
        string str;
        while(n!=nullptr)
        {
            str += std::to_string(n->val) + ", ";
            n = n->next;
        }
        return str;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1,
    new ListNode(2,
    new ListNode(6,
    new ListNode(3,
    new ListNode(4,
    new ListNode(5,
    new ListNode(6)))))));

    cout << s.to_string(head) << endl;;

    s.removeElements(head, 6);

    cout << s.to_string(head) << endl;;

    return 0;
}