#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reorderLinkedList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

     ListNode* oddHead = head;
    ListNode* evenHead = head->next;
    ListNode* oddTail = oddHead;
    ListNode* evenTail = evenHead;

    while (evenTail != nullptr && evenTail->next != nullptr) {
        oddTail->next = evenTail->next;
        oddTail = oddTail->next;
        evenTail->next = oddTail->next;
        evenTail = evenTail->next;
    }

     oddTail->next = evenHead;

    return oddHead;
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

    head = reorderLinkedList(head);

    std::cout << "Reordered Linked List: ";
    printLinkedList(head); // Reordered Linked List: 1 3 5 2 4

    return 0;
}
