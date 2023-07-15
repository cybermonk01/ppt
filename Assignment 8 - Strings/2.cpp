#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<int> parentheses;
    std::stack<int> stars;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '(') {
            parentheses.push(i);
        } else if (c == '*') {
            stars.push(i);
        } else { // c == ')'
            if (!parentheses.empty()) {
                parentheses.pop();
            } else if (!stars.empty()) {
                stars.pop();
            } else {
                return false;
            }
        }
    }

    while (!parentheses.empty() && !stars.empty()) {
        if (parentheses.top() > stars.top()) {
            return false;
        }
        parentheses.pop();
        stars.pop();
    }

    return parentheses.empty();
}

int main() {
    std::string s = "()";
    bool result = isValid(s);
    std::cout << std::boolalpha << "Output: " << result << std::endl; // Output: true
    return 0;
}
