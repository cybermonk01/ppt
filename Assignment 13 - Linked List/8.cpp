#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* deleteNodeAtPosition(Node* head, int position) {
    if (!head) {
        return nullptr; 
    }

    if (position == 1) {
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        return head;
    }

    Node* current = head;
    int count = 1;

    while (current && count < position) {
        current = current->next;
        count++;
    }

    if (!current) {
        return head;  
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    if (current->prev) {
        current->prev->next = current->next;
    }

    delete current;
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
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    std::cout << "Original Doubly Linked List: ";
    printDoublyLinkedList(head);

    int position = 3;
    head = deleteNodeAtPosition(head, position);

    std::cout << "Linked List after deleting position " << position << ": ";
    printDoublyLinkedList(head);

     while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
