#include <iostream>
using namespace std;
template <class T>
class LkList
{
    struct LNode
    {
        T data;
        LNode *next;
    };
    LNode *head;

public:
    LkList();
    virtual ~LkList();
    bool insert_front(T e);
    void traverse();
    bool get(int i, T &e);
    bool set(int i, T e){};
    bool insert(int i, T e);
    void clear()
    {
        LNode *p = head - next, *q;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head->next = 0;
    };
};
template <class T>
LkList<T>::LkList()
{
    head = new LNode();
    if (!head)
        throw "fialed to alloc memory!";
    head->next = 0;
}
template <class T>
LkList<T>::~LkList()
{
    LNode *p = head, *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}
template <class T>
bool LkList<T>::insert_front(T e)
{
    LNode *q = new LNode();
    if (!q)
        return false;
    q->data = e;
    q->next = 0;
    q->next = head->next;
    head->next = q;
    return true;
};
template <class T>
void LkList<T>::traverse()
{
    LNode *p = head->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
template <class T>
bool LkList<T>::get(int i, T &e)
{
    if (i < 1)
        return false;
    LNode *p = head->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return false;
    e = p->data;
    return true;
};
template <class T>
bool LkList<T>::insert(int i, T e)
{
    if (i < 1)
        return false;
    LNode *p = head;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return false;
}
int main()
{
    LkList<char> Lk;
    Lk.insert_front('A');
    Lk.insert_front('B');
    Lk.insert_front('C');
    Lk.traverse();
    char e;
    Lk.get(2, e);
    cout << e << endl;
}