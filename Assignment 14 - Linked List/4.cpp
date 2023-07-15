#include <iostream>
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

     Node* current = head;
    while (current != nullptr) {
        Node* newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

     current = head;
    while (current != nullptr) {
        if (current->random != nullptr) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

     current = head;
    Node* newHead = current->next;
    while (current != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        current = temp->next;
        if (current != nullptr) {
            temp->next = current->next;
        }
    }

    return newHead;
}

 void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
     Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;  
    head->next->random = head;  

    std::cout << "Original Linked List: ";
    printLinkedList(head);  
    Node* newHead = copyRandomList(head);

    std::cout << "Copied Linked List: ";
    printLinkedList(newHead); 

    return 0;
}
