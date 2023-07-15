#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

ListNode* leftShiftLinkedList(ListNode* head, int k) {
    int length = lengthOfLinkedList(head);

     k = k % length;

    if (k == 0) {
        return head;
    }

     int newHeadPosition = length - k;

     ListNode* current = head;
    ListNode* newHead = nullptr;
    ListNode* lastNode = nullptr;

    int position = 0;
    while (current != nullptr) {
        if (position == newHeadPosition) {
            newHead = current;
        }
        if (current->next == nullptr) {
            lastNode = current;
        }
        current = current->next;
        position++;
    }

     lastNode->next = head;

     head = newHead;
    newHead->next = nullptr;

    return head;
}

 void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
     ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original Linked List: ";
    printLinkedList(head); // Original Linked List: 1 2 3 4 5

    int k = 2;
    head = leftShiftLinkedList(head, k);

    std::cout << "Left-Shifted Linked List: ";
    printLinkedList(head); // Left-Shifted Linked List: 3 4 5 1 2

    return 0;
}
