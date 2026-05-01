#include "seqlist.h"
template <class elemType>
seqList<elemType>::~seqList()
{
    delete []data;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentlength = 0;
}

template <class elemType>
int seqList<elemType>::length()const
{
    return currentlength;
}

template <class elemType>
elemType seqList<elemType>::visit(int i)const
{
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse()const
{
    cout<<endl;
    for(int i = 0;i<currentlength ;i++)
    {
        cout<<data[i]<<" ";
    }
}

template<class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new int [initSize];
    maxSize = initSize;
    currentLenghth = 0;  
}

template<class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    for(int i = 0;i<=currentLenghth and i!= x;i++);
    if (i == currentLenghth) return -1;
    return i;
}

template<class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i = 0;i<currentLenghth;i++)
    {
        data[i] = tmp[i];
    }
    delete []tmp;
}

template<class elemType>
void seqList<elemType>::insert(int i,const elemType &x)
{
    if(currentLenghth == maxSize)
    {
        doubleSpace();
    }
    for(int j = currentLenghth;j>i;j--)
    {
        data[j] = data[j - 1];
    }
    data[i] == x;
    currentLenghth++;
}

template<class elemType>
void seqList<elemType>::remove(int i)
{
    for(int j = i;j<currentLenghth - 1;j++)
    {
        data[j] = data[j + 1];
    }
    currentLenghth--;
}

template<class elemType>
void seqList<elemType>::erase(int i)
{
    int tmp = data[i];
    int count = 0;
    for(int j = 0;j<currentLenghth;j++)
    {
        if(data[j] == tmp) count += 1;
        else data[j - count] == data[j];
    }
    currentLenghth -= count;
}