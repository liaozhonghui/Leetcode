#include <iostream>
using namespace std;

// typedef char T;
template <class T>
class SqList
{
    T *data;
    int capacity;
    int n;
    bool realloc();

public:
    SqList(int cap = 100);
    virtual ~SqList()
    {
        cout << "SqList destructor" << endl;
        delete[] data;
        // n = 0;
    };
    bool push_back(T e);
    bool insert(int i, T e);
    bool remove(int i);
    bool get(int i, T &e);
    bool set(int i, T e);
    int size();
    void traverse(void (*fun)(T e));
};
template <class T>
SqList<T>::SqList(int cap)
{
    this->data = new T[cap];
    if (!data)
    {
        cout << "No Memory!" << endl;
    }
    else
    {
        cout << "SqList constructor" << endl;
        capacity = cap;
        n = 0;
    }
}
template <class T>
bool SqList<T>::push_back(T e)
{
    if (n >= capacity)
    {
        if (!realloc())
        {
            return false;
        }
    }
    data[n] = e;
    n++;
};
template <class T>
bool SqList<T>::insert(int i, T e)
{
    if (n >= capacity)
    {
        if (!realloc())
            return false;
    }
    if (i > n + 1 || i < 1)
    {
        return false;
    }
    T *p = &(data[i - 1]);
    T *q = &(data[n - 1]);
    for (; p <= q; --q)
    {
        *(q + 1) = *(q);
    }
    data[i - 1] = e;
    n++;
    return true;
};
template <class T>
bool SqList<T>::remove(int i)
{
    return true;
};
template <class T>
bool SqList<T>::get(int i, T &e)
{
    if (i > n || i < 1)
    {
        return false;
    }
    else
    {
        e = data[i - 1];
    }
    return true;
};
template <class T>
bool SqList<T>::set(int i, T e)
{
    return true;
};
template <class T>
int SqList<T>::size()
{
    return n;
};
template <class T>
void SqList<T>::traverse(void (*fun)(T e))
{
    for (int i = 0; i < n; i++)
    {
        fun(data[i]);
    }
};
template <class T>
bool SqList<T>::realloc()
{
    T *p = new T[2 * capacity];
    if (!p)
        return false;
    for (int i = 0; i < n; i++)
    {
        p[i] = data[i];
    }
    capacity = 2 * capacity;
    delete[] data;
    data = p;
    return true;
}
template <class T>
void Print(T e)
{
    cout << e << endl;
}
int global_n = 0;
void Sum(char e)
{
    global_n += e;
}
int main()
{
    SqList<char> L;
    L.push_back('A');
    L.push_back('B');
    L.push_back('C');
    L.push_back('D');
    char a;
    bool isExist = L.get(3, a);
    if (isExist)
        cout << "find 3 element:" << a << endl;
    L.traverse(Print);
    L.insert(2, 'X');
    L.traverse(Print);
    L.insert(6, 'Z');
    L.traverse(Print);
    cout << "haha" << endl;
    SqList<int> inst;
    inst.push_back('A');
    inst.push_back('B');
    inst.push_back('C');
    inst.push_back('D');
    char a1;
    bool isExist1 = L.get(3, a1);
    if (isExist1)
        cout << "find 3 element:" << a << endl;
    inst.traverse(Print);
    inst.insert(2, 'X');
    inst.traverse(Print);
    inst.insert(6, 'Z');
    inst.traverse(Print);
    cout << "haha" << endl;
}