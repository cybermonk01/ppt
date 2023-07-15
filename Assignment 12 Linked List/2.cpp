#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = head->next;

    if (hasCycle(head)) {
        std::cout << "Output: True (The linked list has a loop)" << std::endl;
    } else {
        std::cout << "Output: False (The linked list does not have a loop)" << std::endl;
    }

    return 0;
}
