#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* addOne(ListNode* head) {
     ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

     int carry = 1;
    current = prev;
    while (current != nullptr) {
        int sum = current->val + carry;
        current->val = sum % 10;
        carry = sum / 10;

        if (carry == 0) {
            break;  
        }

        current = current->next;
    }

     if (carry != 0) {
        ListNode* newCarryNode = new ListNode(carry);
        current->next = newCarryNode;
    }

     prev = nullptr;
    current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

 void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
     ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    std::cout << "Input: ";
    printLinkedList(head1); // Input: 123

    head1 = addOne(head1);

    std::cout << "Output: ";
    printLinkedList(head1); // Output: 124

    return 0;
}
