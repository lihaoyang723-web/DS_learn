#ifndef BTREE_H
#define BTREE_H

template <class T>
class btree
{
    public:
        virtual ~btree() {}
        virtual void clear() = 0;
        virtual bool isempty() const = 0;
        virtual T root(T flag) const = 0;
        virtual T parent(T x, T flag) const = 0;
        virtual T lchild(T x, T flag) const = 0;
        virtual T rchild(T x, T flag) const = 0;
        virtual void deleft(T x) = 0;
        virtual void deright(T x) = 0;
        virtual void preorder() const = 0;
        virtual void midorder() const = 0;
        virtual void postorder() const = 0;
        virtual void levelorder() const = 0;
};

#endif