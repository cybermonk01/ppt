#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> result;
    if (s.empty() || p.empty() || s.length() < p.length())
        return result;

    std::unordered_map<char, int> charFreq;
    for (char c : p) {
        charFreq[c]++;
    }

    int windowSize = p.length();
    int left = 0, right = 0, count = p.length();

    while (right < s.length()) {
         if (charFreq.find(s[right]) != charFreq.end()) {
            charFreq[s[right]]--;
            if (charFreq[s[right]] >= 0)
                count--;
        }

         if (right - left + 1 == windowSize) {
            if (count == 0)
                result.push_back(left);

            if (charFreq.find(s[left]) != charFreq.end()) {
                charFreq[s[left]]++;
                if (charFreq[s[left]] > 0)
                    count++;
            }

            left++;
        }

        right++;
    }

    return result;
}

int main() {
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> result = findAnagrams(s, p);

    std::cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}
