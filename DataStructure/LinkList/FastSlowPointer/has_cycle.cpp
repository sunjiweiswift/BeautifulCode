#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool HasCycle(ListNode* head) {
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

ListNode* FindCycleStart(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast == nullptr) {
            return nullptr;
        }
        fast = fast->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }
    if (fast == nullptr) {
        return nullptr;
    }
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main() {
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