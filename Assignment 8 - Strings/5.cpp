#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int n = chars.size();
    int writeIdx = 0;
    int count = 1;

    for (int i = 1; i <= n; ++i) {
        if (i < n && chars[i] == chars[i - 1]) {
            count++;
        } else {
            chars[writeIdx++] = chars[i - 1];
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char c : countStr) {
                    chars[writeIdx++] = c;
                }
            }
            count = 1;
        }
    }

    return writeIdx;
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = compress(chars);

    std::cout << "Output: " << result << ", and the array: [";
    for (int i = 0; i < result; ++i) {
        std::cout << "'" << chars[i] << "'";
        if (i < result - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}
