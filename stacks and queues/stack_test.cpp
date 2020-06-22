#include<iostream>
#include"stack.cpp"

using namespace std;

main()
{
    Stack<int> stack = Stack<int>();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    while (!stack.is_empty())
        cout << stack.pop() << endl;
}