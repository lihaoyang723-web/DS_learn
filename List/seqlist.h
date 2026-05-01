#ifndef SEQLIST_H
#define SEQLIST_H
#include "list.h"
template <class elemType>
class seqList:public list<elemType>
{
    private:
    elemType *data; //存储线性表元素的数组的起始地址
    int currentLenghth; //线性表的表长
    int maxSize; //数组规模
    void doubleSpace(); //表满扩容一倍
    public:
    seqList(int initSize = 10); //构造函数
    ~seqList(); //析构函数
    void clear(); //清空所有元素
    int length()const; //获取表长
    void insert(int i,const elemType &x); //在第i位插入元素x
    void remove(int i); //移除第i位的元素
    int search(const elemType &x)const; //寻找第i位的元素是否存在，存在返回索引，否则-1
    elemType visit(int i)const; //返回第i个元素
    void traverse()const; //输出所有元素
    void erase(int i); //擦除和data[i]相同的所有元素
};
#endif