/*
    The runner technique means that you iterate through the linked list with two pointers simutaneously,
    with one ahead aof the other. The "fast" node might be ahead by a fixed amount, or it might be hopping
    multiple node for each one node that the "slow" node iterates through.
*/

#include<iostream>

using namespace std;

class Node
{
    public:
    Node *next;
    string data;

    Node(string d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedList
{
    private:
    Node *head;

    public:
    void appendToTail(string d)
    {
        cout << "Inserting " << d << endl;

        if (head == NULL)
        {
            head = new Node(d);
            return;
        }

        Node *n = head;
        while (n->next != NULL)
            n = n->next;
        n->next = new Node(d);

        return;
    }

    string toString()
    {
        string str = "";
        Node* n = head;
        str = str + n->data;
        while(n->next != NULL)
        {
            n = n->next;
            str = str + "->" + n->data;
        }
        return str;
    }

    void weave()
    {
        Node* slow = head;
        Node* fast = head;

        while (fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // when fast hits the end, move to beginning and start waive
        fast = head;
        while (slow->next->next != NULL)
        {
            Node* tmp = slow->next;
            Node* tmp2 = fast->next;
            
            // first pointer adjustment - removal
            slow->next = slow->next->next;

            //second pointer adjustment - insertion
            fast->next = tmp;
            tmp->next = tmp2;

            /* debug */
            // cout << "slow->next: " << slow->next->data << endl;
            // cout << toString() << endl;

            fast = fast->next->next;
        }
        return;
    }
};

main()
{
    LinkedList list = LinkedList();
    list.appendToTail("a1");
    list.appendToTail("a2");
    list.appendToTail("a3");
    list.appendToTail("a4");
    list.appendToTail("a5");
    list.appendToTail("a6");
    list.appendToTail("b1");
    list.appendToTail("b2");
    list.appendToTail("b3");
    list.appendToTail("b4");
    list.appendToTail("b5");
    list.appendToTail("b6");

    cout << list.toString() << endl;

    list.weave();

    cout << list.toString() << endl;
}