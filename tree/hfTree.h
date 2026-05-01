#ifndef HFTREE_H
#define HFTREE_H
#include <string>
template <class T>
class hfTree
{
    private:
        struct node
        {
            T data;
            int weight;
            int parent,left,right;
        };
        node *elem;
        int length;
    public:
        struct hfCode
        {
            T data;
            std::string code;
        };
        hfTree(const T *x,const int *w,int size);
        void getCode(hfCode result []);
        ~hfTree(){delete []elem;}
    };
template <class T>
hfTree<T>::hfTree(const T *v,const int *w,int size)
{
    const int max_int = 32767;
    int min1,min2;
    int x,y;
    length = 2 * size;
    elem = new node [length];
    for(int i = size;i < length;i++)
    {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }
    for(int i = size - 1;i > 0;i--)
    {
        min1 = min2 = max_int;
        x = y = 0;
        for(int j = i + 1;j < length;j++)
        {
            if(elem[j].parent == 0)
            {
                if(elem[j].weight < min1)
                {
                    min2 = min1;
                    min1 = elem[j].weight;
                    x = y;
                    y = j;
                }
                else if(elem[j].weight < min2)
                {
                    min2 = elem[j].weight;
                    x = j;
                }

            }
        }
        elem[i].weight = min1 + min2;
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = i;
        elem[y].parent = i;
    }
} 
template<class T>
void hfTree<T>::getCode(hfCode result[])
{
    int size = length / 2;
    int p,s;
    for(int i = size;i < length;i++)
    {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while(p)
        {
            if(elem[p].left == s)
            {
                result[i - size].code = '0' + result[i - size].code;
            }
            else
            {
                result[i - size].code = '1' + result[i - size].code;
            }
            s = p;
            p = elem[p].parent;
        }
    }
}
#endif