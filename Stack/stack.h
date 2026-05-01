#ifndef STACK_H
#define STACK_H
template <class elemtype>
class stack 
{
    public:
        virtual bool isempty() const = 0;
        virtual void push(const elemtype &x) = 0;
        virtual elemtype pop() = 0;
        virtual elemtype top() const = 0;
        virtual ~stack(){}
};
#endif