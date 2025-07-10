#include <iostream>
#include <vector>
using namespace std;

//all function perform action in O(1) time complexity
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
    Node* head;
    Node* tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);

        if(empty())
        {
            head = newNode;
            tail = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        if(empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    int front()
    {
        if(empty())
        {
            cout << "Queue is empty!" << endl;
            return -999;
        }

        return head->data;
    }

    bool empty()
    {
        return (head == NULL);
    }

    void print()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
    
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.print();
    q.pop();
    q.print();
    return 0;
}