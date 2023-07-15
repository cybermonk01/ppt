#include <iostream>

struct ListNode {
    char val;
    ListNode* next;
    ListNode(char val) : val(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true;  
    }

    ListNode* slow = head;
    ListNode* fast = head;

     while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

     ListNode* secondHalf = reverseList(slow);

     while (head && secondHalf) {
        if (head->val != secondHalf->val) {
            return false;
        }
        head = head->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    ListNode* head1 = new ListNode('R');
    head1->next = new ListNode('A');
    head1->next->next = new ListNode('D');
    head1->next->next->next = new ListNode('A');
    head1->next->next->next->next = new ListNode('R');

    if (isPalindrome(head1)) {
        std::cout << "Output: Yes" << std::endl;
    } else {
        std::cout << "Output: No" << std::endl;
    }

    ListNode* head2 = new ListNode('C');
    head2->next = new ListNode('O');
    head2->next->next = new ListNode('D');
    head2->next->next->next = new ListNode('E');

    if (isPalindrome(head2)) {
        std::cout << "Output: Yes" << std::endl;
    } else {
        std::cout << "Output: No" << std::endl;
    }

    return 0;
}
