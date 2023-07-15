#include <iostream>
#include <string>

int countSubstringsWithSameStartEnd(const std::string& str) {
    int count = 0;
    int n = str.length();

     for (int i = 0; i < n; ++i) {
        char ch = str[i];
        int j = i;

         while (j < n && str[j] == ch) {
            ++j;
            ++count;
        }
    }

    return count;
}

int main() {
    std::string str1 = "abcab";
    std::string str2 = "aba";

    std::cout << "Output 1: " << countSubstringsWithSameStartEnd(str1) << std::endl; // Output: 7
    std::cout << "Output 2: " << countSubstringsWithSameStartEnd(str2) << std::endl; // Output: 4

    return 0;
}
