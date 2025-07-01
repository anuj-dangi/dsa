#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node* head;
    Node* tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void insert(int data, int pos)
    {
        if(pos < 0)
        {
            cout << "invalid pos" << endl;
            return;
        }

        if(pos == 0)
        {
            push_front(5);
            return;
        }

        Node* temp = head;

        for(int i=0;i<pos-1;i++)
        {
            if(temp->next == NULL)
            {
                cout << "invalid pos" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if(newNode->next)
            newNode->next->prev = newNode;
    }

    void push_front(int data)
    {
        if(!head)   
        {
            head = new Node(data);
            tail = head;
            return;
        }

        Node* temp = new Node(data);

        temp->next = head;
        head->prev = temp;
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
        temp->prev = tail;
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
        head->prev = NULL;

        delete temp;
    }

    void pop_back()
    {
        if(!head)
        {
            cout << "list is empty" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }

    void print()
    {
        Node* temp = head;

        while( temp )
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

int main()
{
    DoublyList dl;
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);
    dl.push_back(4);
    dl.pop_front();
    dl.pop_back();
    dl.insert(5, 3);
    dl.print();
    return 0;
}