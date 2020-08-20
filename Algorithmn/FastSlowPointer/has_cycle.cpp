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

bool HasCycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    ListNode* cycleStart = nullptr;
    for (size_t i = 1; i < 100; i++) {

        ListNode* node = new ListNode(i);
        if (i == 5) {
            cycleStart = node;
        }
        pre->next = node;
        pre = node;
    }
    // pre->next = cycleStart;
    if (HasCycle(head)) {
        cout << "Has cycle" << endl;
    } else {
        cout << "Has no cycle" << endl;
    }
}