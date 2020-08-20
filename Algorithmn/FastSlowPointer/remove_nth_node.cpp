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

void RemoveNthNode(ListNode* head, int n)
{
    if (head == nullptr) {
        return;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    for (size_t i = 0; i <= n; i++) {
        if (fast == nullptr) {
            break;
        }
        fast = fast->next;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    for (size_t i = 1; i < 100; i++) {
        ListNode* node = new ListNode(i);
        pre->next = node;
        pre = node;
    }
    RemoveNthNode(head, 3);
    ListNode* node = head;
    while (node != nullptr) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}