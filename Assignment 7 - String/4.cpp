#include <iostream>
#include <algorithm>

std::string reverseWords(std::string s) {
    std::stringstream ss(s);
    std::string word, result;

    while (ss >> word) {
         std::reverse(word.begin(), word.end());
        
         result += word + " ";
    }

     if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    std::string s = "Let's take LeetCode contest";
    std::string reversedSentence = reverseWords(s);

    std::cout << "Reversed sentence: " << reversedSentence << std::endl;

    return 0;
}
