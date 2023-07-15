#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    ListNode* bottom;
    ListNode(int data) : data(data), next(nullptr), bottom(nullptr) {}
};

ListNode* merge(ListNode* a, ListNode* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    ListNode* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    return result;
}

ListNode* flattenLinkedList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

     head->next = flattenLinkedList(head->next);

     head = merge(head, head->next);

    return head;
}

 void printFlattenedLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->bottom;
    }
    std::cout << std::endl;
}

int main() {
     ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(19);
    head->next->bottom = new ListNode(2);
    head->next->bottom->bottom = new ListNode(7);
    head->next->bottom->bottom->bottom = new ListNode(8);
    head->next->next->bottom = new ListNode(3);
    head->next->next->bottom->bottom = new ListNode(11);

    std::cout << "Input: ";
    printFlattenedLinkedList(head); // Input: 5 2 7 8 10 3 11 19

    head = flattenLinkedList(head);

    std::cout << "Output: ";
    printFlattenedLinkedList(head); // Output: 2 3 5 7 8 10 11 19

    return 0;
}
