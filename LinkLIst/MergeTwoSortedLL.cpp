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

// leetcode - 21
// Merge two sorted linked list
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // ListNode dummy(0);
    // ListNode *output = &dummy;
    // ListNode *head = output;

    // while (list1 && list2)
    // {
    //     if (list1->val <= list2->val)
    //     {
    //         output->next = list1;
    //         list1 = list1->next;
    //     }
    //     else
    //     {
    //         output->next = list2;
    //         list2 = list2->next;
    //     }
    //     output = output->next;
    // }

    // while (list1)
    // {
    //     output->next = list1;
    //     list1 = list1->next;
    //     output = output->next;
    // }

    // while (list2)
    // {
    //     output->next = list2;
    //     list2 = list2->next;
    //     output = output->next;
    // }

    // return head->next;

    // Using recursion'

    return merge(list1, list2);
}

ListNode *merge(ListNode *list1, ListNode *list2)
{

    if (list1 == NULL || list2 == NULL)
    {
        return list1 == NULL ? list2 : list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge(list1, list2->next);
        return list2;
    }

    // if (list1 && list2)
    // {
    //     if (list1->val <= list2->val)
    //     {
    //         list1->next = merge(list1->next, list2);
    //         return list1;
    //     }
    //     else
    //     {
    //         list2->next = merge(list1, list2->next);
    //         return list2;
    //     }
    // }
    // else if (list1)
    // {
    //     return list1;
    // }
    // else if (list2)
    // {
    //     return list2;
    // }
    // else
    //     return NULL;
}

int main()
{

    return 0;
}