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

class List
{
    Node* head;
    Node* tail;
public:

    List()
    {
        head = tail = NULL;
    }

    void insert(int data, int pos)
    {
        if(pos < 0) 
        {
            cout << "Invalid pos" << endl;
            return;
        }

        if(pos == 0)
        {
            push_front(data);
            return;
        }

        Node* temp = head;
        Node* newNode = new Node(data);

        for(int i=0;i<pos-1;i++)
        {
            if(temp == NULL){
                cout << "Invalid pos" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;

        temp->next = newNode;
    }

    void push_front(int data)
    {
        //static initialization -> memory get destroyed after this function completion which we do'nt want.
        // Node temp(data);

        //dynamic memory allocation;
        Node* temp = new Node(data);

        if(head == NULL)
        {
            head = tail = temp;
            return;
        }

        temp->next = head;

        head = temp;
    }

    void push_back(int data)
    {
        Node* temp = new Node(data);

        if(head == NULL)
        {
            head = tail = temp;
            return;
        }

        tail->next = temp;

        tail = temp;
    }

    void pop_front()
    {
        if(head == NULL)    return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if(head == NULL)    return;

        Node* temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;

        tail = temp;
    }

    int search(int ele)
    {
        Node* temp = head;
        int index = 0;

        while(temp != NULL)
        {
            if(ele == temp->data)   return index;
            index++;
            temp = temp->next;
        }

        return -1;
    }

    void print()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    List ll;

    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.insert(3, 5);
    ll.print();
    cout << ll.search(2);
    return 0;
}