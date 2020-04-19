#include <iostream>
#include <map>
using namespace std;

// 创建node结构体
struct Node {
    int key, value;
    Node *prev, *next;
    Node(int key, int value) : key(key), value(value), prev(NULL), next(NULL){};
};

// 创建一个双端链表
class DoubleLinkedList {
    Node *front, *rear;
    bool isEmpty() { return rear == NULL; }

   public:
    DoubleLinkedList() : front(NULL), rear(NULL){};
    Node* add_page_to_head(int key, int value) {
        Node* page = new Node(key, value);
    };
    void move_page_to_head(Node* page){};
    void remove_rear_page(){};
    Node* get_rear_page(){};
};

// 创建一个LRU类
class LRUCache {
    int capacity, size;
    DoubleLinkedList* pageList;
    // 使用一种hash表实现：map
    map<int, Node*> pageMap;

   public:
    LRUCache(int c){};
    ~LRUCache(){};
    int get(int key){};
    void put(int key, int value) {}
};

int main() {
    LRUCache cache(2);  // cache capacity 2
    cache.put(2, 2);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cache.put(1, 1);
    cache.put(1, 5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cache.put(8, 8);
    cout << cache.get(1) << endl;
    cout << cache.get(8) << endl;
}