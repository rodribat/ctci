
#include<iostream>
#include"linked_list.cpp"

main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.appendToTail(10);
    linkedList.appendToTail(20);
    linkedList.appendToTail(30);
    linkedList.appendToTail(40);
    linkedList.appendToTail(50);

    cout << linkedList.toString() << endl;

    linkedList.deleteNode(10); // deleting head
    linkedList.deleteNode(40); // deleting intermediate node
    linkedList.deleteNode(50); // deleting tail node

    cout << linkedList.toString() << endl;
}