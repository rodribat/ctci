
// exercise 3.2

#include<iostream>

using namespace std;

template<class T>
class StackNode
{
    public:
    T value;
    StackNode<T> *min_so_far;
    StackNode<T> *next;

    StackNode(T value)
    {
        this->value = value;
        min_so_far = NULL;
        next = NULL;
    }
};

template<class T>
class StackMin
{
    public:
    StackNode<T> *top;
    void push(T value);
    T pop();
    T peek();
    T peek_min();
    string to_string();
    StackMin()
    {
        top = NULL;
    }
};

template<class T>
void StackMin<T>::push(T value)
{
    StackNode<T>* node = new StackNode<int>(value);

    if (top == NULL)
    {
        top = node;
        node->min_so_far = top;
        return;
    }

    node->next = top;
    node->min_so_far = value < top->min_so_far->value ? node : top;

    top = node;
}

template<class T>
T StackMin<T>::pop()
{
    if (top == NULL)
        return -1;

    StackNode<T> *node = top;
    T ret = node->value;

    top = top->next;
    delete node;

    return ret;
}

template<class T>
T StackMin<T>::peek()
{
    if (top == NULL)
        return -1;

    return top->value;
}

template<class T>
T StackMin<T>::peek_min()
{
    if (top == NULL)
        return -1;

    return top->min_so_far->value;
}

template<class T>
string StackMin<T>::to_string()
{
    string str = "";
    StackNode<T> *n = top;
    while (n != NULL)
    {
        str = str + " " + std::to_string(n->value);
        n = n->next;
    }

    return str;
}

main()
{
    StackMin<int> stack = StackMin<int>();
    stack.push(5);
    stack.push(4);
    stack.push(7);
    stack.push(2);
    stack.push(3);
    stack.push(1);
    stack.push(8);
    stack.push(2);

    cout << "Stack: " << stack.to_string() << endl;
    cout << "Minimum: " << std::to_string(stack.peek_min()) << endl << endl;

    cout << "Popping " << stack.pop() << endl;
    cout << "Popping " << stack.pop() << endl;
    cout << "Popping " << stack.pop() << endl;

    cout << "Stack: " << stack.to_string() << endl;
    cout << "Minimum: " << std::to_string(stack.peek_min()) << endl << endl;

    cout << "Popping " << stack.pop() << endl;
    cout << "Popping " << stack.pop() << endl;

    cout << "Stack: " << stack.to_string() << endl;
    cout << "Minimum: " << std::to_string(stack.peek_min()) << endl;
}