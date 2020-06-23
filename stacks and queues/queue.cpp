#include<iostream>

using namespace std;

struct EmptyQueueException: public exception {
    const char * what() const throw() {
        return "EmptyQueueException";
    }
};

template<class T>
class QueueNode
{
    public:
    T data;
    QueueNode<T> *next;

    QueueNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template<class T>
class Queue
{
    private:
    QueueNode<T> *first;
    QueueNode<T> *last;

    public:
    void add(T data);
    T remove();
    T peek();
    bool isEmpty();
    string to_string();
};

template<class T>
void Queue<T>::add(T data)
{
    cout << "Inserting " << std::to_string(data) << endl;

    QueueNode<T> *n = new QueueNode<T>(data);
    if (last==NULL)
    {
        last = n;
        first = last;
    }
    else
    {
        last->next = n;
        last = n;
    }
}

template<class T>
T Queue<T>::remove()
{
    if (first == NULL)
        throw EmptyQueueException();
    
    T ret = first->data;
    QueueNode<T> *n = first;
    first = first->next;
    delete n;

    return ret;
}

template<class T>
T Queue<T>::peek()
{
    if (first == NULL)
        throw EmptyQueueException();
    
    return first->data;
}

template<class T>
bool Queue<T>::isEmpty()
{
    if (first == NULL)
        return true;
    else
        return false;
}

template<class T>
string Queue<T>::to_string()
{
    QueueNode<T> *p = first;
    string str = "";
    while (p!=NULL)
    {
        str = str + std::to_string(p->data) + " ";
        p = p->next;
    }
    
    return str;
}