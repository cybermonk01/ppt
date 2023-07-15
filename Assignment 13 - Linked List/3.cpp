#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseKNodes(ListNode* head, int k) {
    if (!head || k <= 1) {
        return head;
    }

    ListNode* current = head;
    ListNode* prevTail = nullptr;
    ListNode* newHead = nullptr;

    while (current) {
        int count = 0;
        ListNode* prev = nullptr;
        ListNode* nextGroup = nullptr;

        while (current && count < k) {
            nextGroup = current->next;
            current->next = prev;
            prev = current;
            current = nextGroup;
            count++;
        }

        if (!newHead) {
            newHead = prev;
        }

        if (prevTail) {
            prevTail->next = prev;
        }

        while (prevTail && prevTail->next) {
            prevTail = prevTail->next;
        }
    }

    return newHead;
}

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    head = reverseKNodes(head, k);

    printLinkedList(head);

    // Free the memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
