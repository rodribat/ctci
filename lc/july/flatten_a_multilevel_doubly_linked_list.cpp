
/*
    Flatten a Multilevel Doubly Linked List
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/
*/

#include<iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {};
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* n = head;
        while (n != NULL)
        {
            if (n->child != NULL)
            {
                Node* first = n->child;
                Node* last = first;
                
                while(last->next != NULL)
                {
                    last = last->next;
                    if (last->child != NULL)
                        flatten(last);
                }
                
                // pointers adjustment
                Node* next = n->next;
                
                n->next = first;
                first->prev = n;
                
                last->next = next;
                if (next != NULL)
                    next->prev = last;
                
                n->child = NULL;
            }
            n = n->next;
        }
        return head;
    }

    string to_string(Node* head) {
        string s = "[";
        Node* n = head;
        while (n!=NULL)
        {
            s += std::to_string(n->val) + ", ";
            n = n->next;
        }
        s += "]";
        return s;
    }
};

int main()
{
    Solution s;
    /*
        input: [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
        represents:
        [1,2,3,4,5,6]
             +-[7,8,9,10]
                  +-[11,12]
    */

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->next = new Node(10);

    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);

    cout << s.to_string(s.flatten(head)) << endl;
    
    return 0;
}