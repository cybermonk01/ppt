#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* reverseDoublyLinkedList(Node* head) {
    if (!head || !head->next) {
        return head;  
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;  
    }

    return head;
}

void printDoublyLinkedList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(8);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;

    std::cout << "Original Linked List: ";
    printDoublyLinkedList(head);

    head = reverseDoublyLinkedList(head);

    std::cout << "Reversed Linked List: ";
    printDoublyLinkedList(head);

    // Free the memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
