#include <iostream>
#include <vector>

int lastRemaining(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    bool leftToRight = true;
    int remainingCount = n;
    int step = 2;
    int head = 0;

    while (remainingCount > 1) {
        if (leftToRight || remainingCount % 2 == 1) {
            head += step / 2;
        }

        for (int i = head; i < remainingCount; i += step) {
            arr[i] = 0;
        }

        leftToRight = !leftToRight;
        remainingCount /= 2;
        step *= 2;
    }

    for (int num : arr) {
        if (num != 0) {
            return num;
        }
    }

    return -1;  
}

int main() {
    int n = 9;
    std::cout << "Output: " << lastRemaining(n) << std::endl;  

    return 0;
}
