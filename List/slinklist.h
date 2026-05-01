#ifndef SLINKLIST_H
#define SLINKLIST_H

#include "list.h"
template <class elemType>
class slinklist:public list<elemType>
{
    private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x,node *n = nullptr):data(x),next(n){}
        node():next(nullptr){}
        ~node(){}
    };
    node *head; // 头指针
    int currentlength; //表长
    node *move(int i) const; //返回第i个结点的地址
    public:
    slinklist();
    ~slinklist(){clear();delete head;}
    void clear();
    int length()const {return currentlength;}
    void insert(int i,const elemType &x);
    void remove(int i);
    int search (const elemType &x) const;
    elemType visit(int i)const;
    void traverse()const;
};
#endif