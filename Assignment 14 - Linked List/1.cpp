#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* detectAndRemoveLoop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

     while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;  
        }
    }

     if (fast == nullptr || fast->next == nullptr) {
        return head;
    }

     slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;  
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = head->next;  

    head = detectAndRemoveLoop(head);

     std::cout << "Output: ";
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl; // Output: 1 3 4

    return 0;
}
