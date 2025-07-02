#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

//leetcode - 430
//time complexity - O(n)
Node* flatten(Node* head)
{
    if (!head)  return NULL;

    Node* temp = head;

    while( temp )
    {
        if(temp->child != NULL)
        {
            Node* next = temp->next;

            temp->next = flatten(temp->child);
            temp->child = NULL;

            temp->next->prev = temp;

            while( temp->next != NULL )
            {
                temp = temp->next;
            }

            if(next != NULL)
            {
                temp->next = next;
                next->prev = temp;
            }
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    return 0;
}