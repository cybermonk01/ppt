#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void insertAlternate(ListNode* first, ListNode* second) {
    if (!first || !second) {
        return;
    }

    ListNode* firstCurrent = first;
    ListNode* secondCurrent = second;

    while (firstCurrent && secondCurrent) {
        ListNode* firstNext = firstCurrent->next;
        ListNode* secondNext = secondCurrent->next;

        firstCurrent->next = secondCurrent;
        secondCurrent->next = firstNext;

        firstCurrent = firstNext;
        secondCurrent = secondNext;
    }

    // Empty the second list
    second = nullptr;
}

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* first = new ListNode(5);
    first->next = new ListNode(7);
    first->next->next = new ListNode(17);
    first->next->next->next = new ListNode(13);
    first->next->next->next->next = new ListNode(11);

    ListNode* second = new ListNode(12);
    second->next = new ListNode(10);
    second->next->next = new ListNode(2);
    second->next->next->next = new ListNode(4);
    second->next->next->next->next = new ListNode(6);

    std::cout << "First List before: ";
    printLinkedList(first);
    std::cout << "Second List before: ";
    printLinkedList(second);

    insertAlternate(first, second);

    std::cout << "First List after: ";
    printLinkedList(first);
    std::cout << "Second List after: ";
    printLinkedList(second);

    return 0;
}
