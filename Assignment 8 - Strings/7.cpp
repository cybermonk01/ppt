#include <iostream>
#include <string>
#include <stack>

std::string decodeString(std::string s) {
    std::stack<int> repeatCounts;
    std::stack<std::string> strings;
    std::string currentString = "";
    int currentCount = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            currentCount = currentCount * 10 + (c - '0');
        } else if (c == '[') {
            repeatCounts.push(currentCount);
            currentCount = 0;
            strings.push(currentString);
            currentString = "";
        } else if (c == ']') {
            int repeatCount = repeatCounts.top();
            repeatCounts.pop();
            std::string prevString = strings.top();
            strings.pop();

            for (int i = 0; i < repeatCount; ++i) {
                prevString += currentString;
            }

            currentString = prevString;
        } else {
            currentString += c;
        }
    }

    return currentString;
}

int main() {
    std::string s = "3[a]2[bc]";
    std::string result = decodeString(s);

    std::cout << "Output: " << result << std::endl; 

    return 0;
}
