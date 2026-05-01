#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <stdexcept>
#include "stack.h"
template <class elemtype>
class seqstack :public stack<elemtype>
{
    private:
        elemtype *elem;
        int top_p;
        int maxsize;
        void doublespace();
    public :
        seqstack(int initsize = 10);
        ~seqstack();
        seqstack(const seqstack &) = delete;
        seqstack &operator=(const seqstack &) = delete;
        bool isempty()const;
        void push(const elemtype &x);
        elemtype pop();
        elemtype top() const;

};

template <class elemtype>
seqstack<elemtype>::seqstack(int initsize):maxsize(initsize)
{
    if (initsize <= 0)
    {
        throw std::invalid_argument("initial size must be positive");
    }
    elem = new elemtype[initsize];
    top_p = -1;
}

template <class elemtype>
seqstack<elemtype>::~seqstack()
{
    delete [] elem;
}

template <class elemtype>
void seqstack<elemtype>::doublespace()
{
    elemtype *tmp = elem;
    elem = new elemtype[maxsize * 2];
    for(int i = 0;i <= top_p;i++)
    {
        elem[i] = tmp[i];
    }
    delete []tmp;
    maxsize *= 2;
}

template <class elemtype>
bool seqstack<elemtype>::isempty()const
{
    return top_p == -1;
}

template <class elemtype>
void seqstack<elemtype>::push(const elemtype &x)
{
    if(top_p == maxsize - 1) doublespace();
    elem[++top_p] = x;
}

template <class elemtype>
elemtype seqstack<elemtype>::pop()
{
    if (isempty())
    {
        throw std::out_of_range("pop from empty stack");
    }
    return elem[top_p--];
}

template<class elemtype>
elemtype seqstack<elemtype>::top()const
{
    if (isempty())
    {
        throw std::out_of_range("top from empty stack");
    }
    return elem[top_p];
}

#endif