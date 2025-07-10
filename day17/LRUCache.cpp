#include <iostream>
#include <unordered_map>
using namespace std;

//leetcode - 146
//get, put each run in O(1) average time complexity
class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> m;
    int limit;
    LRUCache(int capacity)
    {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            int value = m[key]->value;

            put(key, value);

            return value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {
            Node *oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(key, value);

        addNode(newNode);
        m[key] = newNode;
    }

    void addNode(Node *newNode)
    {
        Node *oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void deleteNode(Node *node)
    {
        Node *temp = node;

        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    return 0;
}