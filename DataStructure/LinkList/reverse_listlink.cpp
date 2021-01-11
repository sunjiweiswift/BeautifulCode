#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* ReverseListLink(ListNode* root) {
    ListNode* newHead = new ListNode(0);
    ListNode* curNode = root;
    while (curNode != nullptr) {
        ListNode* nextNode = curNode->next;
        curNode->next = newHead->next;
        newHead->next = curNode;
        curNode = nextNode;
    }
    return newHead->next;
}
int main() {
    // Generate ListLink 10,9...0
    ListNode* node = new ListNode(10);
    ListNode* root = node;
    for (int i = 9; i >= 0; i--) {
        node->next = new ListNode(i);
        node = node->next;
    }
    cout << "before reverse" << endl;
    node = root;
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    // Reverse listlink
    node = ReverseListLink(root);
    // Print
    cout << "after reverse" << endl;
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}