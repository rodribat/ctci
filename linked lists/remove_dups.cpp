
#include<iostream>
#include"linked_list.cpp"
#include<map>

using namespace std;

// remove dups using a dictionary - O(n)
void removeDups(LinkedList list)
{
    map<int, int> dict = map<int, int>();

    Node* n = list.getHead();
    dict[n->data]++;

    while(n->next != NULL)
    {
        if(dict[n->next->data] > 0)
        {
            Node* tmp = n->next;
            n->next = n->next->next;
            delete tmp;
        }
        else
        {
            n = n->next;
            dict[n->data]++;
        }
    }
};

// remove dups without auxiliar data structure - O(n²)
void removeDups2(LinkedList list)
{
    Node *n1, *n2;
    for (n1=list.getHead(); n1->next!=NULL; n1=n1->next)
        for (n2=n1; n2->next!=NULL; )
        {
            cout << "n1=" << n1->data << " n2=" << n2->next->data << endl;
            
            if (n1->data == n2->next->data)
            {
                cout << "removendo " << n1->data << endl;
                Node *tmp = n2->next;
                if (n2->next != NULL)
                {
                    n2->next = n2->next->next;
                    n2 = n2->next;
                }
                else
                    n2->next = NULL;
                delete tmp;
            }
        }
};

main()
{
    LinkedList list = LinkedList();
    list.appendToTail(1);
    list.appendToTail(3);
    list.appendToTail(7);
    list.appendToTail(5);
    list.appendToTail(3);
    list.appendToTail(2);
    list.appendToTail(6);
    list.appendToTail(9);
    list.appendToTail(2);
    list.appendToTail(1);

    cout << list.toString() << endl;

    removeDups2(list);

    cout << list.toString() << endl;
}