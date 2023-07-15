#include <iostream>
#include <string>

void generatePermutations(std::string& str, int start, int end) {
    if (start == end) {
        std::cout << str << " ";
        return;
    }

    for (int i = start; i <= end; ++i) {
        std::swap(str[start], str[i]);
        generatePermutations(str, start + 1, end);
        std::swap(str[start], str[i]);  
    }
}

void printAllPermutations(std::string str) {
    int n = str.length();
    generatePermutations(str, 0, n - 1);
}

int main() {
    std::string str1 = "cd";
    std::string str2 = "abb";

    std::cout << "Output 1: ";
    printAllPermutations(str1);
    std::cout << std::endl;

    std::cout << "Output 2: ";
    printAllPermutations(str2);
    std::cout << std::endl;

    return 0;
}
