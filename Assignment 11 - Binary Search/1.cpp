#include <iostream>

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 1, right = x;
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int x = 4;
    int sqrtValue = mySqrt(x);
    std::cout << "The square root of " << x << " is: " << sqrtValue << std::endl;
    return 0;
}
