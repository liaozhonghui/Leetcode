#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *quick = head->next;
        while (slow != quick)
        {
            if (quick == NULL || quick->next == NULL)
            {
                return false;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        return true;
    }
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *quick = head;
        while (quick->next && quick->next->next)
        {
            quick = quick->next->next;
            if (slow == quick)
            {
                return true;
            }
            else
            {
                slow = slow->next;
            }
        }
        return false;
    }
};