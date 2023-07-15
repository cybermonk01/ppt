#include <iostream>
#include <string>

bool canBeEqualBySwap(std::string s, std::string goal) {
    if (s.length() != goal.length())
        return false;

    int mismatchCount = 0;
    int firstMismatchIndex = -1;
    int secondMismatchIndex = -1;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != goal[i]) {
            mismatchCount++;
            if (mismatchCount == 1) {
                firstMismatchIndex = i;
            } else if (mismatchCount == 2) {
                secondMismatchIndex = i;
            }
        }
    }

    if (mismatchCount == 0)
        return true;
    if (mismatchCount != 2)
        return false;

     return (s[firstMismatchIndex] == goal[secondMismatchIndex] && s[secondMismatchIndex] == goal[firstMismatchIndex]);
}

int main() {
    std::string s = "ab";
    std::string goal = "ba";

    bool result = canBeEqualBySwap(s, goal);
    std::cout << std::boolalpha << "Output: " << result << std::endl; // Output: true

    return 0;
}
