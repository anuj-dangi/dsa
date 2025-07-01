#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    return 0;
}

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//leetcode - 138
//Copy list with random pointer
//time complexity - O(n)
Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;

    unordered_map<Node *, Node *> um;

    Node *oldtemp = head;
    Node *newhead = new Node(oldtemp->val);
    um.emplace(oldtemp, newhead);
    Node *newtemp = newhead;
    oldtemp = oldtemp->next;

    while (oldtemp)
    {
        Node *temp = new Node(oldtemp->val);
        newtemp->next = temp;
        um.emplace(oldtemp, temp);
        newtemp = newtemp->next;
        oldtemp = oldtemp->next;
    }

    oldtemp = head;

    while (oldtemp)
    {
        um[oldtemp]->random = um[oldtemp->random];
        oldtemp = oldtemp->next;
    }

    return newhead;
}