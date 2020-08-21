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

ListNode* RemoveNthNode(ListNode* head, int n)
{
    if (head == nullptr || n == 0) {
        return nullptr;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    for (size_t i = 1; i < 20; i++) {
        ListNode* node = new ListNode(i);
        pre->next = node;
        pre = node;
    }

    ListNode* node = RemoveNthNode(head, 2);
    while (node != nullptr) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}