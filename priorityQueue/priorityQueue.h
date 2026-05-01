#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
template <class T>
class priorityQueue
{
    public:
        priorityQueue(int capacity = 100);
        priorityQueue(const T data[],int size);
        ~priorityQueue();
        bool isEmpty()const;
        void enQueue(const T &x);
        T deQueue();
        T getHead()const;
    private:
        int currentSize;
        T *array;
        int maxSize;

    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};

template <class T>
priorityQueue<T>::priorityQueue(int capacity)
{
    array = new T [capacity];
    maxSize = capacity;
    currentSize = 0;
}

template <class T>
priorityQueue<T>::~priorityQueue()
{
    delete []array;
}

template <class T>
bool priorityQueue<T>::isEmpty()const
{
    return currentSize == 0;
}

template <class T>
T priorityQueue<T>::getHead()const
{
    return array[1];
}

template <class T>
void priorityQueue<T>::enQueue(const T &x)
{
    if (currentSize == maxSize - 1) doubleSpace();
    int hole = ++ currentSize;
    for(;hole > 1 and x < array[hole / 2];hole /= 2)
    {
        array[hole] = array[hole / 2];
    }
    array[hole]= x; 
}

template <class T>
T priorityQueue<T>::deQueue()
{
    T minItem;
    minItem = array[1];
    array[1] = array[currentSize --];
    percolateDown(1);
    return minItem;
}

template <class T>
void priorityQueue<T>::percolateDown(int hole)
{
    int child;
    T tmp = array [hole];
    for(;hole * 2 <= currentSize;hole = child)
    {
        child = hole * 2;
        if(child != currentSize and array [child + 1] < array[child])
        {
            child ++;
        }
        if(array[child] < tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}

template <class T>
void priorityQueue<T>::buildHeap()
{
    for(int i = currentSize / 2;i > 0;i --)
    {
        percolateDown(i);
    }
}

template <class T>
priorityQueue<T>::priorityQueue(const T *items,int size):maxSize(size + 10),currentSize(size)
{
    array = new T [maxSize];
    for(int i = 0;i < size;i ++)
    {
        array[i + 1] = items[i];
    }
    buildHeap();
}

template <class T>
void priorityQueue<T>::doubleSpace()
{
    T *tmp = array;
    maxSize *= 2;
    array = new T [maxSize];
    for(int i = 0;i <= currentSize;i ++)
    {
        array[i] = tmp[i];
    }
    delete []tmp;
}
#endif