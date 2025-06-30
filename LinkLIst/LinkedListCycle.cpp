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

//leetcode - 141
//using slow-fast approach
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while ( fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ListNode a(7);
    ListNode temp(2, &a);
    ListNode head(5, &temp);
    a.next = &head;
    cout << hasCycle(&head);
    return 0;
}