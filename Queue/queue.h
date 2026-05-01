#ifndef QUEUE_H
#define QUEUE_H
template<class elemtype>
class queue
{
    public:
        virtual bool isempty ()const = 0;
        virtual void enqueue(const elemtype &x) = 0;
        virtual elemtype dequeue() = 0;
        virtual elemtype gethead()const = 0;
        virtual ~queue(){}
};
#endif