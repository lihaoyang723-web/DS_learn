#include "slinklist.h"
template <class elemType>
slinklist<elemType>::slinklist()
{
    head = new node;
    currentlength = 0;
}
template <class elemType>
void slinklist<elemType>::clear()
{
    node *p = head ->next,*q;
    head -> next = nullptr;
    while(p->next != nullptr)
    {
        q = p -> next;
        delete p;
        p = q;
    }
    currentlength = 0;
}
template <class elemType>
slinklist<elemType>::node *slinklist<elemType>::move(int i) const
{
    node *p = head;
    while(i > 0)
    {
        p = p->next;
        i--;
    }
    return p;
}
template <class elemType>
void slinklist<elemType>::insert(int i,const elemType &x)
{
    node *tmp = move(i - 1);
    tmp -> next = new node (x,tmp->next);
    currentlength ++;
}
template <class elemType>
void slinklist<elemType>::remove(int i)
{
    node *p = move(i - 1);
    p -> next = p->next->next;
}
template <class elemType>
int slinklist<elemType>::search(const elemType &x) const
{
    node *p = head;
    int i = 0;
    while(p!=nullptr and p->data != x)
    {
        i++;
        p = p->next;
    }
    if(p == nullptr) return -1;
    return i;
}
template <class elemType>
elemType slinklist<elemType>::visit(int i)const
{
    // node *p = move(i);
    // return p->data;
    return move(i)->data;
}
template <class elemType>
void slinklist<elemType>::traverse()const
{
    node *p = head->next;
    while(p != nullptr)
    {
        std:cout<<p->data<<" ";
        p = p->next; 
    } 
    std::cout << std::endl;
}