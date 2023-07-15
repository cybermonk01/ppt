#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int findNthFromEnd(ListNode* head, int N) {
    if (!head || N <= 0) {
        return -1;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    for (int i = 0; i < N; ++i) {
        if (fast == nullptr) {
            return -1;
        }
        fast = fast->next;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;
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

    int N = 2;
    int result = findNthFromEnd(head, N);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
