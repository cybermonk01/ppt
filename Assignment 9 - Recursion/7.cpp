#include <iostream>
#include <string>

void generatePermutations(std::string& str, int start, int end) {
    if (start == end) {
        std::cout << str << std::endl;
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
    std::string S1 = "ABC";
    std::string S2 = "XY";

    std::cout << "Output 1: " << std::endl;
    printAllPermutations(S1);

    std::cout << "Output 2: " << std::endl;
    printAllPermutations(S2);

    return 0;
}
