#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseAlternateKNodes(ListNode* head, int k, bool reverseNext) {
    if (!head) {
        return nullptr;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    int count = 0;

     while (current && count < k) {
        next = current->next;

        if (reverseNext) {
            current->next = prev;
        }

        prev = current;
        current = next;
        count++;
    }

 
    if (reverseNext) {
        head->next = reverseAlternateKNodes(current, k, !reverseNext);
        return prev;
    } else {
        head->next = current;
        return head;
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    std::cout << "Linked List before: ";
    printLinkedList(head);

    int k = 3;
    head = reverseAlternateKNodes(head, k, true);

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
