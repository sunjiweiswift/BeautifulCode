#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

int FindMidValue(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    for (size_t i = 1; i < 100; i++)
    {
        ListNode* node = new ListNode(i);
        pre->next = node;
        pre = node;
    }
    cout << FindMidValue(head) << endl;
}