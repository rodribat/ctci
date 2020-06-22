#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
    Node *next;
    T data;

    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template<class T>
class LinkedList
{
    private:
    Node<T> *head;

    public:
    Node<T>* getHead()
    {
        return head;
    }

    void appendToTail(T d)
    {
        cout << "Inserting " << d << endl;

        if (head == NULL)
        {
            head = new Node<T>(d);
            return;
        }

        Node<T> *n = head;
        while (n->next != NULL)
            n = n->next;
        n->next = new Node<T>(d);

        return;
    }

    void deleteNode(T d)
    {
        cout << "Deleting " << d << endl;

        if (head->data == d)
        {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;

            return;
        }

        Node<int>* n = head;
        while (n->next != NULL)
        {
            if (n->next->data == d)
            {
                Node<T>* tmp = n->next;
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
        Node<T>* n = head;
        str = str + to_string(n->data);
        while(n->next != NULL)
        {
            n = n->next;
            str = str + " " + to_string(n->data);
        }
        return str;
    }
};