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

//Merge k sorted lists
//leetcode - 23
//most optimized time complexity - O(m*log(n))
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
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    //time complexity - O(m*n)
    // if (lists.size() == 0)
    //     return NULL;
    // else if (lists.size() == 1)
    // {
    //     return lists[0];
    // }
    // ListNode *output = merge(lists[0], lists[1]);

    // for (int i = 2; i < lists.size(); i++)
    // {
    //     output = merge(output, lists[i]);
    // }

    // return output;

    //more optimized approach using divide and conquer

    if(lists.empty())   return NULL;

    return divide(lists, 0, lists.size()-1);
}

ListNode* divide(vector<ListNode*> lists, int l, int r)
{
    if( l == r )    return lists[l];

    int mid = l + (r-l)/2;

    ListNode* l1 = divide(lists, l, mid);
    ListNode* l2 = divide(lists, mid+1, r);

    return merge(l1, l2);
}

int main()
{

    return 0;
}