# C++前驱知识

## List（表）
- ArrayList
静态数组
```c++
char a=new Char(100);int n=0;
```
动态内存块
```c++
int capacity=0;
T* data=new T(capacity);int n=0;
...
if(n>capacity){
    T* p=new T(2*capacity);
    if(p){
        for(int i=0;i<n;i++){p[i]=data[i]}
        capacity=2*capacity;
        delete[] data;
        data=p;
    }else{
        cout>>"no enough memory">>endl;
    }
}
```
- sequential list顺序表实现

```c++
template <class T>
class SqList{
    T* data;
    int capacity;
    int n;
}
public:
    SqList(int cap=100){data=new T(cap);capacity=cap;n=0;};
    bool pushBack(T e){
        if(n>=capacity){
            if(!realloc()){
                return false;
            }
        }
        n++;
        data[n]=e;
    };
    bool insert(int i,T e){
        if(i<1||i>n+1){
            cout<<"out of range"<<endl;
            return false;
        }
        if(n>=capacity){
            if(!realloc()){
                return false;
            }
        }
        T *q=&(data[i-1]);
        for(T *p=&(data[n-1];p>=q;--p)){
            *(p+1)=*p;
        }
    };
    bool remove(int i);
    bool insertFront(T e);
    bool get(int i,T &e);
    bool set(int i,T e);
    int size(){return n;};
    int find((*fun)());
    void traverser((*fun)());

private:
    bool realloc(){
        T* p=new T[capacity*2];
        if(!p){
            cout<<"out of memory";
            return false;
        }else{
            for(int i=0;i<n;i++){p[i]=data[i];}
            capacity=capacity*2;
            delete[] data;
            data=p;
            return true;
        }
    }
```