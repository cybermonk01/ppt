#include <iostream>
#include <string>

int stringLengthRecursive(const std::string& str, int index) {
    if (index == str.length()) {
        return 0;
    }
    return 1 + stringLengthRecursive(str, index + 1);
}

int stringLength(const std::string& str) {
    return stringLengthRecursive(str, 0);
}

int main() {
    std::string str1 = "abcd";
    std::string str2 = "GEEKSFORGEEKS";

    std::cout << "Output 1: " << stringLength(str1) << std::endl; // Output: 4
    std::cout << "Output 2: " << stringLength(str2) << std::endl; // Output: 13

    return 0;
}
