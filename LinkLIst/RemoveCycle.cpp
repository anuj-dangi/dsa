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
//using slow-fast approach
void removeCycle(ListNode *head)
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
            ListNode* prev;
            while (fast != slow)
            {
                prev = fast;
                fast = fast->next;
                slow = slow->next;
            }

            prev->next = NULL;      //remove cycle

        }
    }
}

int main()
{
    ListNode a(7);
    ListNode temp(2, &a);
    ListNode head(5, &temp);
    a.next = &head;
    removeCycle(&head);
    return 0;
}