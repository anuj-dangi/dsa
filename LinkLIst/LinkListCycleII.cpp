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
//leetcode - 142
//using slow-fast approach
//https://excalidraw.com/#json=UUun_kHsoCekRGG0OwHG7,fEdbTL_6AYEiyUeuQznLmA
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main()
{
    ListNode a(7);
    ListNode temp(2, &a);
    ListNode head(5, &temp);
    a.next = &head;
    cout << detectCycle(&head);
    return 0;
}