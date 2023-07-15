#include <iostream>
#include <string>
#include <cctype>

int countConsonants(const std::string& str) {
    int count = 0;
    for (char ch : str) {
        if (std::isalpha(ch) && !std::strchr("aeiouAEIOU", ch)) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::string str1 = "abc de";
    std::string str2 = "geeksforgeeks portal";

    std::cout << "Output 1: " << countConsonants(str1) << std::endl; // Output: 3
    std::cout << "Output 2: " << countConsonants(str2) << std::endl; // Output: 12

    return 0;
}

