#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "btree.h"
#include "../Queue/linkQueue.h"
template <class T>
class binaryTree:public btree<T>
{
    friend void printTree(const binaryTree &t,T flag);
    private:
        struct node
        {
            node *left,*right;
            T data;

            node():left(nullptr),right(nullptr){}
            node(T data):left(nullptr),right(nullptr),data(data){}
            node(T data,node *left,node *right):data(data),left(left),right(right){}
            ~node(){}
        };
        node *rootNode;
        node *find(T x,node *t)const;
        void clear(node *&t);
        void preorder(node *t)const;
        void midorder(node *t)const;
        void postorder(node *t)const;
    public:
        binaryTree():rootNode(nullptr){}
        binaryTree(T x){rootNode = new node(x);}
        ~binaryTree(){clear();}
        void clear();
        bool isempty()const;
        T root(T flag)const;
        T lchild(T x,T flag)const;
        T rchild(T x,T flag)const;
        void deleft(T x);
        void deright(T x);
        void preorder()const;
        void midorder()const;
        void postorder()const;
        void levelorder()const;
        void createTree(T flag);
        T parent(T x,T flag)const {return flag;}
};
template <class T>
bool binaryTree<T>::isempty()const
{
    return rootNode == nullptr;
}
template <class T>
T binaryTree<T>::root(T flag)const
{
    if(rootNode == nullptr) return flag;
    return rootNode -> data;
}
template <class T>
void binaryTree<T>::clear(binaryTree<T>::node *&t)
{
    if(t == nullptr) return ;
    clear(t -> left);
    clear(t -> right);
    delete t;
    t = nullptr;
}
template<class T>
void binaryTree<T>::clear()
{
    clear(rootNode);
}
template<class T>
void binaryTree<T>::preorder(binaryTree<T>::node *t)const
{
    if(t == nullptr) return ;
    std::cout << t -> data << ' ';
    preorder(t -> left);
    preorder(t -> right);
}
template <class T> 
void binaryTree<T>::preorder()const
{
    std::cout << "\npreorder:\n";
    preorder(rootNode);
}
template <class T>
void binaryTree<T>::postorder(binaryTree<T>::node*t)const
{
    if(t == nullptr) return ;
    postorder(t -> left);
    postorder(t -> right);
    std::cout << t -> data << " ";
}
template <class T>
void binaryTree<T>::postorder()const
{
    std::cout << "\npostorder:\n";
    postorder(rootNode);
}
template <class T>
void binaryTree<T>::midorder(binaryTree<T>::node*t)const
{
    if(t == nullptr) return ;
    midorder(t -> left);
    std::cout << t -> data << " ";
    midorder(t -> right);
}
template <class T>
void binaryTree<T>::midorder()const
{
    std::cout << "\nmidorder:\n";
    midorder(rootNode);
}
template <class T>
void binaryTree<T>::levelorder()const
{
    linkQueue<node *>que;
    node *tmp;
    if(rootNode == nullptr) return;
    que.enqueue(rootNode);
    while(!que.isempty())
    {
        tmp = que.dequeue();
        std::cout << tmp -> data << " ";
        if(tmp -> left) que.enqueue(tmp -> left);
        if(tmp -> right) que.enqueue(tmp -> right);
    }
}
template <class T>
binaryTree<T>::node *binaryTree<T>::find(T x,binaryTree<T>::node *t)const 
{
    if(t == nullptr)  return nullptr;
    if(t -> data == x) return t;
    node * tmp;
    if((tmp = find(x,t -> left)) != nullptr) return tmp;
    else return find(x,t -> right);
}
template <class T>
void binaryTree<T>::deleft(T x)
{
    node * tmp = find(x,rootNode);
    if(tmp == nullptr) return ;
    clear(tmp -> left);
}
template <class T>
void binaryTree<T>::deright(T x)
{
    node * tmp = find(x,rootNode);
    if(tmp == nullptr) return ;
    clear(tmp -> right);
}
template <class T>
T binaryTree<T>::lchild(T x,T flag)const
{
    node * tmp = find(x,rootNode);
    if(tmp == nullptr or tmp -> left == nullptr) return flag;
    return tmp -> left -> data;
}
template <class T>
T binaryTree<T>::rchild(T x,T flag)const
{
    node *tmp = find(x,rootNode);
    if(tmp == nullptr or tmp -> right == nullptr) return flag;
    return tmp -> right -> data;
}
template <class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<node *> que;
    node * tmp;
    T x,ldata,rdata;

    std::cout << "ninput the root node:\n" ;
    std::cin >> x;
    clear();
    rootNode = new node (x);
    que.enqueue(rootNode);

    while(!que.isempty())
    {
        tmp = que.dequeue();
        std::cout << "input " << tmp -> data << " 's sons(" << flag << "represents the empty node):\n";
        std::cin >> ldata >> rdata;
        if(ldata != flag) que.enqueue(tmp -> left = new node (ldata));
        if(rdata != flag) que.enqueue(tmp -> right = new node (rdata));
    }    
    std::cout << "create completed!\n"; 
}
template <class T>
void printTree(const binaryTree<T>&t ,T flag)
{
    linkQueue<T>que;
    T p = t.root(flag);
    if(p == flag) return;
    que.enqueue(p);
    std::cout << std::endl;
    while(!que.isempty())
    {
        T l,r;
        p = que.dequeue();
        l = t.lchild(p,flag);
        r = t.rchild(p,flag);
        std::cout << p << " " << l << " " << r << std::endl;
        if(l != flag) que.enqueue(l);
        if(r != flag) que.enqueue(r);
    }
}
#endif