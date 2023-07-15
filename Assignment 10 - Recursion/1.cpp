#include <iostream>

bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}

int main() {
    int n1 = 27;
    int n2 = 9;
    int n3 = 45;

    std::cout << "Output 1: " << std::boolalpha << isPowerOfThree(n1) << std::endl;  
    std::cout << "Output 2: " << std::boolalpha << isPowerOfThree(n2) << std::endl;  
    std::cout << "Output 3: " << std::boolalpha << isPowerOfThree(n3) << std::endl;  

    return 0;
}
