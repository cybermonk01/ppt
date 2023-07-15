#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void removeLoop(ListNode* head) {
    if (!head) {
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (!fast || !fast->next) {
        return;
    }

    ListNode* startOfLoop = head;
    while (startOfLoop != slow) {
        startOfLoop = startOfLoop->next;
        slow = slow->next;
    }

    ListNode* lastNode = slow;
    while (lastNode->next != slow) {
        lastNode = lastNode->next;
    }

    lastNode->next = nullptr;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = head->next;

    std::cout << "Before: ";
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    removeLoop(head);

    std::cout << "After: ";
    current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
