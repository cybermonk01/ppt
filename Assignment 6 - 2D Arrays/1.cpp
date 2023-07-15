#include <iostream>
#include <vector>
#include <string>

std::vector<int> reconstructPermutation(std::string s) {
    int n = s.size();
    int start = 0, end = n;
    std::vector<int> perm;

    for (char ch : s) {
        if (ch == 'I') {
            perm.push_back(start);
            start++;
        } else {
            perm.push_back(end);
            end--;
        }
    }

     perm.push_back(start);

    return perm;
}

 void printPermutation(std::vector<int>& perm) {
    for (int num : perm) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string s = "IDID";
    std::vector<int> perm = reconstructPermutation(s);

    printPermutation(perm); // Output: 0 4 1 3 2

    return 0;
}
