#include <iostream>
using namespace std;

class CircularQueue
{
    int* arr;
    int f;
    int rear;
    int capacity;
    int currSize;

public:
    CircularQueue(int size)
    {
        f = 0;
        rear = -1;
        currSize = 0;

        arr = new int[size];

        capacity = size;
    }

    void push(int data)
    {
        if(currSize == capacity)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        rear = (rear+1)%capacity;

        arr[rear] = data;
        currSize++;
    }

    void pop()
    {
        if(currSize == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        f = (f+1)%capacity;
        currSize--;
    }

    int front()
    {
        if(currSize == 0)
        {
            cout << "Queue is empty!" << endl;
            return -999;
        }

        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }

};

int main()
{
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.pop();
    cq.push(4);
    while(!cq.empty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }

    cout << endl;
    return 0;
}