#include <iostream>
#include <unordered_map>

bool isStrobogrammatic(std::string num) {
    std::unordered_map<char, char> validPairs = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'9', '6'},
        {'8', '8'}
    };

    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        if (validPairs.find(num[left]) == validPairs.end() || validPairs[num[left]] != num[right]) {
            return false;  
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    std::string num = "69";

    if (isStrobogrammatic(num)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
