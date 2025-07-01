#include <iostream>
#include <vector>
using namespace std;

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

class CircularList
{
    Node* head;
    Node* tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void push_front(int data)
    {
        if(!head)   
        {
            head = new Node(data);
            head->next = head;
            tail = head;
            return;
        }

        Node* temp = new Node(data);

        temp->next = head;
        tail->next = temp;
        head = temp;
    }

    void push_back(int data)
    {
        if(!head)   
        {
            head = new Node(data);
            tail = head;
            return;
        }

        Node* temp = new Node(data);

        tail->next = temp;
        temp->next = head;
        tail = temp;
    }

    void pop_front()
    {
        if(!head)
        {
            cout << "list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;

        delete temp;
    }

    void pop_back()
    {
        if(!head)
        {
            cout << "list is empty" << endl;
            return;
        }

        Node* temp = head;

        while( temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = head;

    }

    void print()
    {
        if(head == NULL)    return;

        cout << head->data << "->";
        Node* temp = head->next;

        while( temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

int main()
{
    CircularList cl;
    cl.push_front(3);
    cl.push_front(2);
    cl.push_front(1);
    cl.push_back(4);
    cl.pop_front();
    cl.pop_back();
    cl.print();
    return 0;
}