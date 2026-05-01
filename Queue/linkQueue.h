#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <stdexcept>
#include "queue.h"
template <class elemtype>
class linkQueue:public queue<elemtype>
{
    private:
        struct node{
            elemtype data;
            node *next;
            node():next(nullptr){}
            node(const elemtype &x,node *n = nullptr):data(x),next(n){}
            ~node(){}
        };
        node *front,*rear;
    public:
        linkQueue();
        ~linkQueue();
        bool isempty()const;
        void enqueue(const elemtype &x);
        elemtype dequeue();
        elemtype gethead()const;
};  
template <class elemtype>
linkQueue<elemtype>::linkQueue()
{
    front = rear = nullptr;
}
template <class elemtype>
linkQueue<elemtype>::~linkQueue()
{
    while(front!=nullptr)
    {
        node *tmp = front;
        front = front -> next;
        delete tmp;
    }
}
template <class elemtype>
bool linkQueue<elemtype>::isempty()const
{
    return front == nullptr;
}
template <class elemtype>
void linkQueue<elemtype>::enqueue(const elemtype &x)
{
    if(front == nullptr)
    {
        front = rear = new node (x);
    }
    else 
    {
        rear ->next = new node (x);
        rear = rear -> next;
    }
}
template <class elemtype>
elemtype linkQueue<elemtype>::dequeue()
{
    if (isempty())
    {
        throw std::out_of_range("dequeue from empty queue");
    }
    node *tmp = front;
    elemtype x = front -> data;
    front = front -> next;
    if(front == nullptr) rear = nullptr; 
    delete tmp;
    return x;
}
template<class elemtype>
elemtype linkQueue<elemtype>::gethead()const
{
    if (isempty())
    {
        throw std::out_of_range("gethead from empty queue");
    }
    return front -> data;
} 
#endif