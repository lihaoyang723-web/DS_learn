#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <stdexcept>
#include "stack.h"
template <class elemtype>
class linkstack:public stack<elemtype>
{
    private:
    struct node{
        elemtype data;
        node *next;
        node(const elemtype &x,node *n = nullptr):data(x),next(n){}
        node():next(nullptr){}
        ~node(){}
    };
    node *top_p;
    public:
    linkstack();
    ~linkstack();
    linkstack(const linkstack &) = delete;
    linkstack &operator=(const linkstack &) = delete;
    bool isempty()const;
    void push(const elemtype &x);
    elemtype pop();
    elemtype top()const;
};

template<class elemtype>
bool linkstack<elemtype>::isempty()const
{
    return top_p == nullptr;
}

template<class elemtype>
linkstack<elemtype>::linkstack()
{
    top_p = nullptr;
}

template <class elemtype>
linkstack<elemtype>::~linkstack()
{
    node *tmp;
    while(top_p != nullptr)
    {
        tmp = top_p;
        top_p = top_p -> next;
        delete tmp;
    }
}

template<class elemtype>
void linkstack<elemtype>::push(const elemtype &x)
{
    top_p = new node (x,top_p);
}

template <class elemtype>
elemtype linkstack<elemtype>::pop()
{
    if (isempty())
    {
        throw std::out_of_range("pop from empty stack");
    }
    node *tmp = top_p;
    elemtype x = top_p -> data;
    top_p = top_p -> next;
    delete tmp;
    return x;
}

template <class elemtype>
elemtype linkstack<elemtype>::top()const
{
    if (isempty())
    {
        throw std::out_of_range("top from empty stack");
    }
    return top_p->data;
}

#endif