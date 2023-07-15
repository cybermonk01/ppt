#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void deleteLastOccurrence(ListNode*& head, int key) {
    if (!head) {
        return; 
    }

    ListNode* lastOccurrence = nullptr;
    ListNode* prevLastOccurrence = nullptr;
    ListNode* current = head;

    while (current) {
        if (current->val == key) {
            lastOccurrence = current;
        }
        current = current->next;
    }

    current = head;
    while (current && current != lastOccurrence) {
        prevLastOccurrence = current;
        current = current->next;
    }

    if (lastOccurrence) {
        if (prevLastOccurrence) {
            prevLastOccurrence->next = lastOccurrence->next;
        } else {
            head = head->next; 
        }
        delete lastOccurrence;
    }
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
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(10);

    int key = 2;

    std::cout << "Linked List before deletion: ";
    printLinkedList(head);

    deleteLastOccurrence(head, key);

    std::cout << "Linked List after deletion: ";
    printLinkedList(head);

    // Free the memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
