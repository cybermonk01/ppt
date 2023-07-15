#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    std::unordered_map<int, ListNode*> sumMap;
    int cumulativeSum = 0;
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    sumMap[cumulativeSum] = dummyHead;

    while (head != nullptr) {
        cumulativeSum += head->val;
        if (sumMap.find(cumulativeSum) != sumMap.end()) {
             ListNode* start = sumMap[cumulativeSum]->next;
            int sumToDelete = cumulativeSum;
            while (start != head) {
                sumToDelete += start->val;
                sumMap.erase(sumToDelete);
                start = start->next;
            }
            sumMap[cumulativeSum]->next = head->next;
        } else {
            sumMap[cumulativeSum] = head;
        }
        head = head->next;
    }

    return dummyHead->next;
}

 void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
     ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* result = removeZeroSumSublists(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(result);
    // Output: Modified Linked List: 3 -> 1 -> nullptr

    return 0;
}
