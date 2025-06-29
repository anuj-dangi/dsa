#include <iostream>
#include <vector>
using namespace std;

//leetcode - 206
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{

    ListNode *nextNode = NULL;
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp != NULL)
    {
        nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }

    return prev;
}

int main()
{
    return 0;
}