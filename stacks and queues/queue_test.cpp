#include<iostream>
#include"queue.cpp"

using namespace std;

main()
{
    Queue<int> queue = Queue<int>();

    queue.add(10);
    queue.add(20);
    queue.add(30);
    queue.add(40);
    queue.add(50);

    cout << queue.to_string() << endl;

    while(!queue.isEmpty())
        cout << queue.remove() << endl;
}