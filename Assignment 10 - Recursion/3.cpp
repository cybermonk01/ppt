#include <iostream>
#include <string>

void generateSubsets(const std::string& set, std::string currentSubset, int index) {
    if (index == set.length()) {
        std::cout << "{" << currentSubset << "}" << std::endl;
        return;
    }

     generateSubsets(set, currentSubset + set[index], index + 1);

     generateSubsets(set, currentSubset, index + 1);
}

void printAllSubsets(const std::string& set) {
    generateSubsets(set, "", 0);
}

int main() {
    std::string set1 = "abc";
    std::string set2 = "abcd";

    std::cout << "Output 1: " << std::endl;
    printAllSubsets(set1);

    std::cout << "Output 2: " << std::endl;
    printAllSubsets(set2);

    return 0;
}
