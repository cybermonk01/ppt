#include <iostream>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

std::vector<int> nextGreaterNodes(ListNode* head) {
    std::vector<int> answer;
    std::stack<std::pair<int, int>> st; 

     ListNode* current = head;
    int index = 0;
    while (current != nullptr) {
         while (!st.empty() && current->val > st.top().first) {
            answer[st.top().second] = current->val;
            st.pop();
        }

        st.push({current->val, index});
        answer.push_back(0);  
        current = current->next;
        index++;
    }

    return answer;
}

int main() {
     ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    std::vector<int> answer = nextGreaterNodes(head);

    std::cout << "Next Greater Nodes: ";
    for (int val : answer) {
        std::cout << val << " ";
    }
 
    return 0;
}
