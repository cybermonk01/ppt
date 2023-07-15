
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeGreater(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2) {
        return nullptr;  
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (list1 && list2) {
        ListNode* newNode = new ListNode(std::max(list1->val, list2->val));

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        list1 = list1->next;
        list2 = list2->next;
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
    ListNode* list1 = new ListNode(5);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(8);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(7);
    list2->next->next = new ListNode(4);
    list2->next->next->next = new ListNode(5);

    std::cout << "List 1: ";
    printLinkedList(list1);
    std::cout << "List 2: ";
    printLinkedList(list2);

    ListNode* newList = mergeGreater(list1, list2);

    std::cout << "New List: ";
    printLinkedList(newList);

    // Free the memory
    while (newList) {
        ListNode* temp = newList;
        newList = newList->next;
        delete temp;
    }

    return 0;
}
