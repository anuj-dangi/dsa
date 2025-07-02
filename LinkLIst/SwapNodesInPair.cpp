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

//leetcode - 24
//time complexity - O(n)
ListNode *swapPairs(ListNode *head)
{
    // ListNode *temp = head;
    // ListNode *prev = NULL;

    // for (int i = 0; i < 2; i++)
    // {
    //     if (temp == NULL)
    //         return head;
    //     prev = temp;
    //     temp = temp->next;
    // }

    // ListNode *nextNode = swapPairs(temp);
    // temp = head;
    // ListNode *prevNode = NULL;
    // ListNode *next = NULL;

    // for (int i = 0; i < 2; i++)
    // {
    //     next = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = temp->next;
    // }

    // head->next = nextNode;
    // return prev;

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* first = head;
    ListNode* sec = head->next;
    ListNode* prev = NULL;

    while( first != NULL && sec != NULL)
    {
        ListNode* third = sec->next;

        first->next = third;
        sec->next = first;

        if(prev != NULL){
            prev->next = sec;
        }
        else
        {
            head = sec;
        }
        prev = first;
        first = third;
        if(third != NULL)
        {
            sec = first->next;
        }
        else
        {
            sec = NULL;
        }

    }

    return head;
}


int main()
{
    return 0;
}