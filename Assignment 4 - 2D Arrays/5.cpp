#include <iostream>

int countCompleteRows(int n) {
    int k = 0;
    int sum = 0;

    while (sum <= n) {
        k++;
        sum = (k * (k + 1)) / 2;
    }

    return k - 1;
}

int main() {
    int n = 5;
    int result = countCompleteRows(n);

    std::cout << "Output: " << result << std::endl; // Output: 2

    return 0;
}
