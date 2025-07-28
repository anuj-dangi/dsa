#include <iostream>
#include <vector>
using namespace std;

//leetcode - 19
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int size = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    int val = size - n + 1;

    temp = head;
    ListNode *prev = NULL;
    ListNode *next = head->next;

    for (int i = 1; i < val; i++)
    {
        next = next->next;
        prev = temp;
        temp = temp->next;
    }

    if (val != 1)
    {
        prev->next = next;
        delete (temp);
    }
    else
    {
        head = head->next;
    }

    return head;
}

int main()
{
    return 0;
}