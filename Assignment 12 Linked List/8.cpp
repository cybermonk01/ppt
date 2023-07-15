#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

bool isCircular(ListNode* head) {
    if (!head) {
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head;

    if (isCircular(head)) {
        std::cout << "The linked list is circular." << std::endl;
    } else {
        std::cout << "The linked list is not circular." << std::endl;
    }

    return 0;
}
