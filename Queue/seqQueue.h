#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include <stdexcept>
#include "queue.h"
template <class elemtype>
class seqQueue:public queue<elemtype>
{
    private:
        elemtype *elem;
        int maxsize;
        int front,rear;
        void doublespace();
    public:
        seqQueue(int size = 10);
        ~seqQueue();
        seqQueue &operator=(const seqQueue &) = delete;
        bool isempty()const;
        void enqueue(const elemtype &x);
        elemtype dequeue();
        elemtype gethead()const;
};
template <class elemtype>
seqQueue<elemtype>::seqQueue(int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("queue size must be positive");
    }
    elem = new elemtype [size];
    maxsize = size;
    front = rear = 0;
}
template <class elemtype>
seqQueue<elemtype>::~seqQueue()
{
    delete []elem;
}
template <class elemtype>
bool seqQueue<elemtype>::isempty()const
{
    return rear == front;
}  
template <class elemtype>
void seqQueue<elemtype>::doublespace()
{
    elemtype *tmp = elem;
    elem = new elemtype[maxsize * 2];
    for (int i = 1;i < maxsize ;i++)
    {   
        elem[i] = tmp[(front + i) % maxsize];
    }
    front = 0;
    rear = maxsize - 1;
    maxsize *= 2;
    delete []tmp;
}
template <class elemtype>
void seqQueue<elemtype>::enqueue(const elemtype &x)
{
    if((rear + 1) % maxsize == front) doublespace();
    rear = (rear + 1) % maxsize;
    elem[rear] = x;

}
template <class elemtype>
elemtype seqQueue<elemtype>::dequeue()
{
    if (isempty())
    {
        throw std::out_of_range("deQueue from empty queue");
    }
    front = (front + 1) % maxsize;
    return elem[front];
}
template <class elemtype>
elemtype seqQueue<elemtype>::gethead()const
{
    if (isempty())
    {
        throw std::out_of_range("getHead from empty queue");
    }
    return elem[(front + 1) % maxsize];
}
#endif