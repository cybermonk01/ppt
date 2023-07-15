#include <iostream>
#include <string>

bool rotateString(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
        return false;  
    }

    return (s + s).find(goal) != std::string::npos;
}

int main() {
    std::string s = "abcde";
    std::string goal = "cdeab";

    if (rotateString(s, goal)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
