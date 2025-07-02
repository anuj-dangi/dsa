#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head, int k)
{

    if(head == NULL)    return NULL;

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

//leetcode - 25
ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    int i=0;
    ListNode* temp = head;
    ListNode* prev = NULL;

    for(int i=0;i<k;i++)
    {
        if(temp == NULL)
        {
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    ListNode* newHead = reverseList(head, k);
    head->next = reverseKGroup(temp, k);

    return  newHead;
}


int main()
{
    return 0;
}