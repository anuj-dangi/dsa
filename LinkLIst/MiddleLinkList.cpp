#include <iostream>
#include <vector>
using namespace std;

//leetcode - 876
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Slow fast pointer approach
ListNode *middleLinkList(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

int main()
{
    return 0;
}