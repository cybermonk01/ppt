#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void removeDuplicates(ListNode* head) {
    if (!head) {
        return;  
    }

    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; 
        } else {
            current = current->next;  
        }
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
    ListNode* head = new ListNode(11);
    head->next = new ListNode(11);
    head->next->next = new ListNode(11);
    head->next->next->next = new ListNode(21);
    head->next->next->next->next = new ListNode(43);
    head->next->next->next->next->next = new ListNode(43);
    head->next->next->next->next->next->next = new ListNode(60);

    std::cout << "Linked List before: ";
    printLinkedList(head);

    removeDuplicates(head);

    std::cout << "Linked List after: ";
    printLinkedList(head);

    // Free the memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
