#include<iostream>

using namespace std;

class Node
{
    public:
    Node *next;
    int data;

    Node(int d)
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
    Node* getHead()
    {
        return head;
    }

    void appendToTail(int d)
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

    void deleteNode(int d)
    {
        cout << "Deleting " << d << endl;

        if (head->data == d)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;

            return;
        }

        Node* n = head;
        while (n->next != NULL)
        {
            if (n->next->data == d)
            {
                Node* tmp = n->next;
                n->next = n->next->next;
                delete tmp;
                return;
            }
            n = n->next;
        }

        return;
    }

    string toString()
    {
        string str = "";
        Node* n = head;
        str = str + to_string(n->data);
        while(n->next != NULL)
        {
            n = n->next;
            str = str + " " + to_string(n->data);
        }
        return str;
    }
};