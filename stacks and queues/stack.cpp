
#include<iostream>

using namespace std;

template<class T>
class StackNode
{
    public:
    T data;
    StackNode *next;

    StackNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template<class T>
class Stack
{
    private:
    StackNode<T> *top;

    public:
    void push(T data)
    {
        StackNode<T> *n = new StackNode<T>(data);

        if (top != NULL)
            n->next = top;

        top = n;
    }

    T pop()
    {
        if (top == NULL)
            return -1;
        
        T ret = top->data;
        StackNode<T> *tmp = top;
        top = top->next;
        delete tmp;

        return ret;
    }

    T peek()
    {
        if (top == NULL)
            return -1; //exception
        
        return top->data;
    }

    bool is_empty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
};