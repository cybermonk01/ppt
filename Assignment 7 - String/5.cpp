#include <iostream>
#include <string>

std::string reverseSegment(std::string& s, int start, int end) {
    while (start < end) {
        std::swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

std::string reverseStr(std::string s, int k) {
    int n = s.length();
    for (int i = 0; i < n; i += 2 * k) {
        int start = i;
        int end = std::min(i + k - 1, n - 1);
        s = reverseSegment(s, start, end);
    }
    return s;
}

int main() {
    std::string s = "abcdefg";
    int k = 2;
    std::string reversedStr = reverseStr(s, k);

    std::cout << "Reversed string: " << reversedStr << std::endl;

    return 0;
}
