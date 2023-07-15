#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* skipMdeleteN(ListNode* head, int M, int N) {
    if (!head || M <= 0 || N <= 0) {
        return head;  
    }

    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current) {
         for (int i = 0; i < M && current; ++i) {
            prev = current;
            current = current->next;
        }

         for (int i = 0; i < N && current; ++i) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }

         prev->next = current;
    }

    return head;
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

    std::cout << "Linked List before: ";
    printLinkedList(head);

    int M = 2;
    int N = 2;
    head = skipMdeleteN(head, M, N);

    std::cout << "Linked List after: ";
    printLinkedList(head);

    return 0;
}
