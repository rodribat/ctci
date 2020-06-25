
// exercise 3.2

#include<iostream>

using namespace std;

template<class T>
class StackNode
{
    public:
    T value;
    StackNode<T> *next;
    StackNode(T value)
    {
        this->value;
        next = NULL;
    }
};

template<class T>
class StackMin
{
    public:
    StackNode<T> top;
    StackNode<T> min;
    void push(T value);
    T pop();
    T peek();
    T min();
    string to_string();
    StackMin()
    {
        top = NULL;
        min = NULL;
    }
};

template<class T>
void StackMin<T>::push(T value)
{
    StackNode<T>* node = new StackNode<int>(value);

    if (top == NULL)
    {
        top = node;
        min = top;
        return;
    }

    node->next = top;
    top = node;
    if (value < min->value)
        min = node;
}

template<class T>
T StackMin<T>::pop()
{
    if (top == NULL)
        return -1;

    StackNode<T> *node = top;
    T ret = node->value;

    top = top->next;

    //update minimun
    if (node == min)
    {
        StackNode<T> * n = top->next, min = top;
        while (n != NULL)
        {
            if (min->value > n->value)
                min = n;
            n = n->next;
        }
    }
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
T StackMin<T>::min()
{
    if (min == NULL)
        return -1;

    return min->value;
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

    cout << "Minimum: " << std::to_string(stack.min()) << endl;
}