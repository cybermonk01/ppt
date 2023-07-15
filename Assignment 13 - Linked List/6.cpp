#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeSortedLists(ListNode* a, ListNode* b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }

    ListNode* head;
    if (a->val < b->val) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }

    ListNode* current = head;

    while (a && b) {
        if (a->val < b->val) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    if (a) {
        current->next = a;
    } else {
        current->next = b;
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
    ListNode* a = new ListNode(5);
    a->next = new ListNode(10);
    a->next->next = new ListNode(15);

    ListNode* b = new ListNode(2);
    b->next = new ListNode(3);
    b->next->next = new ListNode(20);

    std::cout << "List a: ";
    printLinkedList(a);
    std::cout << "List b: ";
    printLinkedList(b);

    ListNode* mergedList = mergeSortedLists(a, b);

    std::cout << "Merged List: ";
    printLinkedList(mergedList);

    // Free the memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
